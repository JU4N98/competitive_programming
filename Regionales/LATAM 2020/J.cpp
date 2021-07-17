#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef LASCALONETA
#else
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
bitset<100000000> visi;


struct Hash{
	size_t operator()(const int &a)const
	{
		size_t s=hash<int>()(a);
		return hash<int>()(0)+0x9e3779b9+(s<<6)+(s>>2);
	}
	size_t operator()(const vector<int> &v)const
	{
		size_t s=0;
		for(auto &e : v) s^=hash<int>()(e)+0x9e3779b9+(s<<6)+(s>>2);
		return s;
	}
};
unordered_map<int, int, Hash> m, m2;

int num[8]={0,0,0,0,0,0,0,0};
int num2[8]={0,0,0,0,0,0,0,0};
int pm=0;
vector<vector<int>> masks;

void precalc(int pos, int acum){
	if(pos==8){
		int idx=0;
		forn(i,8) forn(j,num[i]){ num2[idx]=i+1; idx++;}
		int idf=0;
		dforn(i,acum){
			idf*=8;
			idf+=num2[i];
		}
		vector<int> maski;
		int mask=0;
		forn(i,pow(2,acum)){
			mask=0;
			dforn(j,acum){
				if(i&(1<<j)) mask*=8, mask+=num2[j];
			}
			if(!visi.test(mask)){maski.pb(mask);visi.set(mask);}
		}
		forn(i,pow(2,acum)){
			mask=0;
			dforn(j,acum){
				if(i&(1<<j)) mask*=8, mask+=num2[j];
			}
			visi.reset(mask);
		}
		m2[idf]=pm;
		masks.pb(maski);
		pm++;
	}else{
		forr(i,acum,9){
			num[pos]=i-acum;
			precalc(pos+1,i);
		}
	}
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	precalc(0,0);
	
	int n,k;
	cin>>n>>k;
	
	
	vector<int> arr,idfs;
	forn(N,n){
		char ope;
		cin>>ope;
		if(ope=='C'){
			int cant;
			cin>>cant;
			arr.resize(cant);
			forn(i,cant) cin>>arr[i];
			sort(arr.begin(),arr.end());
			int idf=0;
			dforn(i,sz(arr)){
				idf*=8;
				idf+=arr[i];
			}
			int sub = m2[idf];
			forn(i,sz(masks[sub])){
				m[masks[sub][i]]++;
			}
			idfs.pb(idf);
		}else if(ope=='D'){
			int id;
			cin>>id;
			int sub = m2[idfs[id-1]];
			forn(i,sz(masks[sub])){
				m[masks[sub][i]]--;
			}
		}else{
			int cant;
			cin>>cant;
			arr.resize(cant);
			forn(i,cant) cin>>arr[i];
			sort(arr.begin(),arr.end());
			int idf=0;
			dforn(i,cant) idf*=8, idf+=arr[i];
			cout<<m[idf]<<"\n";
		}
	}
	
	return 0;
}




