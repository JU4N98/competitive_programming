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
//#define ANARAP
//#define operacion(x,y) ((x)+(y))


#ifdef ANARAP
	//#define MAXN 10000
#else
	//#define MAXN 310000
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
/*
typedef ll Elem;
typedef ll Alt;

const Elem neutro=0; const Alt neutro2=0;
struct RMQ{
	int sz;
	Elem t[4*MAXN];
	Alt dirty[4*MAXN];
	Elem &operator[] (int p) {return t[sz+p];}
	void init(int n){
		sz=1<<(32-__builtin_clz(n));
		forn(i,2*sz) t[i]=neutro;
		forn(i,2*sz) dirty[i]=neutro2;
	}
	void updall(){dforn(i,sz) t[i]=operacion(t[2*i],t[2*i+1]);}
	void push(int n, int a , int b){
		if(dirty[n]!=neutro2){
			t[n]+=dirty[n]*(b-a);
			if(n<sz){
				dirty[2*n]+=dirty[n];
				dirty[2*n+1]+=dirty[n];
			}
			dirty[n]=neutro2;
		}
	}
	Elem get(int i, int j, int n, int a, int b){
		if(j<=a || i>=b) return neutro;
		push(n,a,b);
		if(i<=a && b<=j) return t[n];
		int c=(a+b)/2;
		return operacion(get(i,j,2*n,a,c),get(i,j,2*n+1,c,b));
	}
	Elem get(int i,int j){return get(i,j,1,0,sz);}
	void alterar(Alt val, int i, int j, int n, int a, int b){
		push(n,a,b);
		if(j<=a || i>=b) return;
		if(i<=a && b<=j){
			dirty[n] +=val;
			push(n,a,b);
			return;
		}
		int c = (a+b)/2;
		alterar(val,i,j,2*n,a,c), alterar(val, i,j, 2*n+1,c,b);
		t[n]=operacion(t[2*n],t[2*n+1]);
	}
	void alterar(Alt val, int i, int j){alterar(val,i,j,1,0,sz);}
};
*/
int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
		ll n,q;
		cin>>n>>q;
		map<ll,ll> m;
		forn(i,n){
			ll aux;
			cin>>aux;
			if(m.find(aux)==m.end()) m[aux]=i;
		}
		vector<ll> vec(51);
		forall(it,m){
			vec[it->fst]=it->snd;
		}
		//forn(i,51){
		//	cout<<vec[i]<<" ";
		//}
		//cout<<endl;
		forn(i,q){
			ll aux;
			cin>>aux;
			forn(j,vec.size()){
				if(vec[j]<vec[aux]) vec[j]++;
			}
			cout<<vec[aux]+1<<" ";
			vec[aux]=0;
		}
		cout<<"\n";
	
	
	
	return 0;
}




