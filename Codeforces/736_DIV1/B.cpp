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
typedef ll tipo;

#define MAXN 200010
#define operacion(x, y) __gcd(x, y)
const tipo neutro=0;
tipo t[MAXN*4];

struct RMQ {
	int sz;
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
	
	ll te; cin>>te;
	ll arr[MAXN],dif[MAXN];
	RMQ stree; 
	
	forn(T,te){
		ll n; cin>>n;
		forn(i,n) cin>>arr[i];
		if(n==1){ cout<<"1\n"; continue;}
		forr(i,1,n) dif[i-1]=abs(arr[i]-arr[i-1]);

		stree.init(n-1);
		forn(i,n-1) stree.set(i,dif[i]);
		ll ans=0,j=0;
		forn(i,n-1){
			while(j<=i && stree.get(j,i+1)==1) j++;
			ans = max(ans,i-j+2);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}




