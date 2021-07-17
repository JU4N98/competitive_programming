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
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef ll Elem;
typedef ll Alt;

#define operacion(x,y) ((x)+(y))
const Elem neutro=0; const Alt neutro2=0;
#define MAXN 100010//Cambiar segun el N del problema

struct RMQ{
	int sz;
	Elem t[4*MAXN];
	Alt dirty[4*MAXN];
	Elem &operator[](int p) {return t[sz+p];}
	void init(int n){
		sz = 1 << (32-__builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
		forn(i, 2*sz) dirty[i] = neutro2;
	}
	void updall() {dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);}
	void push(int n, int a, int b) {
		if(dirty[n] != neutro2) {
			t[n] += dirty[n]*(b-a);
			if(n<sz){
				dirty[2*n] += dirty[n];
				dirty[2*n+1] += dirty[n];
			}
			dirty[n] = neutro2;
		}
	}
	Elem get(int i, int j, int n, int a, int b) {
		if(j<=a || i>=b) return neutro;
		push(n, a, b);
		if(i<=a && b<=j) return t[n];
		int c = (a+b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	Elem get(int i, int j) {return get(i,j,1,0,sz);}
	
	void alterar(Alt val, int i, int j, int n, int a, int b) {
		push(n, a, b);
		if(j<=a || i>=b) return;
		if(i<=a && b<=j){
			dirty[n] += val; 
			push(n, a, b);
			return;
		}
		int c = (a+b)/2;
		alterar(val, i, j, 2*n, a, c), alterar(val, i, j, 2*n+1, c, b);
		t[n] = operacion(t[2*n], t[2*n+1]);
	}
	void alterar(Alt val, int i, int j){alterar(val,i,j,1,0,sz);}
};

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin>>n;
	set<ii,greater<ii>> s;
	set<ii>range;
	forn(i,n){
		ll in;
		cin>>in;
		s.insert({in,i});
	}
	
	RMQ ans;
	ans.init(n);
	range.insert({0,n-1});
	
	forn(i,n){
		ii p = *(s.begin());
		s.erase(s.begin());
		
		ii p2;
		if(range.lower_bound({p.snd,0})==range.end() || (range.lower_bound({p.snd,0}))->fst>p.snd) p2 = *(prev(range.lower_bound({p.snd,0})));
		else p2 = *(range.lower_bound({p.snd,0}));
		range.erase(p2);
		
		if(p2.fst==p2.snd) continue;
		range.insert({p.snd,p.snd});
		if(p.snd-1>=p2.fst){
			if(p2.fst==0){
				ans.alterar(1,p2.fst,p.snd);
			}else{
				ans.alterar(1,p.snd-(p.snd-p2.fst)/2,p.snd);
			}
			range.insert({p2.fst,p.snd-1});
		}
		if(p.snd+1<=p2.snd){
			if(p2.snd==n-1){
				ans.alterar(1,p.snd+1,p2.snd+1);
			}else{
				ans.alterar(1,p.snd+1,p.snd+(p2.snd-p.snd)/2+1);
			}
			range.insert({p.snd+1,p2.snd});
		}
	}
	forn(i,n) if(i) cout<<" "<<ans.get(i,i+1); else cout<<ans.get(i,i+1);
	cout<<"\n";
	
	return 0;
}




