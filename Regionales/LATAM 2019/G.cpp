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
#define MAXN 200010

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

pair<int, int> sf[MAXN];

bool sacomp(int lhs, int rhs) {return sf[lhs] < sf[rhs];}

vector<int> constructSA(string& s) { 
	int n = int(s.size()); 
	vector<int> sa(n), r(n);
	forn(i,n) r[i] = s[i];
	for(int m=1; m<n; m*=2) {
		forn(i,n) sa[i] = i, sf[i] = {r[i], i+m<n ? r[i+m] : -1};
		stable_sort(sa.begin(), sa.end(), sacomp); 
		r[sa[0]] = 0;
		forr(i,1,n) r[sa[i]] = sf[sa[i]]!=sf[sa[i-1]] ? i : r[sa[i-1]];
	}
	return sa;
}

int tam;
ii lu_bound(string &t, vector<int> &sa, int l, int r, int idx, char c){
	int li = l, ri=r;
	while(li<ri){
		int med = (li+ri)/2;
		if(med==tam || t[sa[med]+idx]<c){
			li=med+1;
		}else{
			ri=med;
		}
	}
	ii ans = {li,tam};
	
	li=l,ri=r;
	while(li<ri){
		int med = (li+ri)/2;
		if(med==tam || t[sa[med]+idx]<=c){
			li=med+1;
		}else{
			ri=med;
		}
	}
	ans.snd=li;
	return ans;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string t; cin>>t;
	vector<int> sa = constructSA(t);
	
	tam = sz(t);
	forn(i,tam+2) t+="$";
	
	int n; cin>>n;
	forn(i,n){
		string s; cin>>s;
		int idx=0,l=0, r=tam,count=1;
		bool nuevo=true,ok=true;
		forn(j,sz(s)){
			ii lu = lu_bound(t,sa,l,r,idx,s[j]);
			if(lu.fst==lu.snd){
				if(nuevo) ok=false;
				else{
					count++;
					nuevo=true;
					j--;
					idx=0;
					l=0,r=tam;
				}
			}else{
				nuevo=false;
				l=lu.fst,r=lu.snd;
				idx++;
			}
			if(!ok) break;
		}
		if(ok) cout<<count<<"\n";
		else cout<<"-1\n";
	}
	
	
	return 0;
}




