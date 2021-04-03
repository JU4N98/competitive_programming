#include <bits/stdc++.h>
#define forr(i,a,b) for(ll i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP
#define MAXN 100001
#define operacion(x,y) max(x,y)
#ifdef ANARAP
#else
#endif

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef long long tipo;
const tipo neutro = 0;

struct RMQ{
	int sz;
	tipo t[4*MAXN];
	tipo &operator[](int p){return t[sz+p];}
	void init(int n){
		sz = 1<<(32 - __builtin_clz(n));
		forn(i,2*sz) t[i] = neutro;
	}
	
	void updall() {dforn(i,sz) t[i]=operacion(t[2*i],t[2*i+1]);}
	tipo get(int i, int j) {return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b){
		if(j<=a || i>=b) return neutro;
		if(i<=a && b<=j) return t[n];
		int c = (a+b)/2;
		return operacion(get(i,j,2*n,a,c), get(i,j,2*n+1,c,b));
	}
	
	void set(int p, tipo val){
		p+=sz;
		while(p>0 && t[p]!=val){
			t[p] = val;
			p/=2;
			val = operacion(t[p*2],t[p*2+1]);
		}
	}
};

int main(){
	#ifdef ANARAP
	 freopen("input.in", "r", stdin);
	 #endif
	 
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 
	 ll n;
	 cin>>n;
	 vector<pair<ll,ll>> color1(n),color2;
	 forn(i,n) cin>>color1[i].fst>>color1[i].snd;
	 color2=color1;
	 sort(color2.begin(),color2.end());
	 map<pair<ll,ll>,ll> m;
	 map<ll,ll> mi;
	 ll val=1;
	 forn(i,n){
		 if(m.find(color2[i])==m.end()){
			 m[color2[i]]=val;
			 mi[val]=color2[i].snd-color2[i].fst+1;
			 val++;
			
		 }
	 }
	 vector<ll> after(n);
	 forn(i,n){
		 after[i]=m[color1[i]];
	 }
	 
	 RMQ segtree;
	 segtree.init(n+2);
	 forn(i,n){
		 ll val1 = mi[after[i]];
		 segtree.set(after[i],segtree.get(0,after[i])+val1);
		 
	 }
	 
	 cout<<segtree.get(0,n+2)<<endl;
	 
	 
	 
	 return 0;
}


