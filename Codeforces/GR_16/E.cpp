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
typedef pair<int,int> ii;
typedef int tipo;

#define MAXN 100010
#define operacion(x, y) x+y
const tipo neutro=0;

struct RMQ {
	int sz;
	tipo t[4*MAXN];
	tipo &operator[](int p) {return t[sz+p];}
	void init(int n) {//O(nlgn)
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
	}
	void updall() {dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);} //O(n)
	tipo get(int i, int j) {return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b) {//O(lgn), [i, j)
		if(j<=a || i>=b) return neutro;
		if(i<=a && b<=j) return t[n];//n = node of range [a,b)
		int c = (a+b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	void set(int p, tipo val) {//O(lgn)
		p += sz;
		while(p>0 && t[p]!=val) {
			t[p] = val;
			p /= 2;
			val = operacion(t[p*2], t[p*2+1]);
		}
	}
};


int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin>>t;
	RMQ stree; stree.init(100000);
	forn(T,t){
		int n,m; cin>>n>>m;
		vector<int> peo(n*m), sea(n*m);
		forn(i,n*m) cin>>peo[i];
		sea=peo; sort(sea.begin(),sea.end());
		set<pair<int,ii>> s;
		forn(i,n*m) s.insert({sea[i],{-i/m,i%m}});
		forn(i,n*m) stree.set(i,1);
		int ans=0;
		
		dforn(i,n*m){
			pair<int,ii> pp = *( s.lower_bound({peo[i],{-301,0}}));
			int row = -pp.snd.fst, col = pp.snd.snd;
			s.erase(pp);
			//cout<<row*m<<" " <<row*m+col<<endl;
			ans += stree.get(row*m,row*m+col);
			stree.set(row*m+col,0);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}




