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
#define operacion(x, y) max(x, y)

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef ll tipo;

const ll INF = 1e15;
const tipo neutro= -INF;

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
	
	int find(int n, int a, int b, ll cur){
		if(b-a == 1) return a;
		
		int c = (a+b)/2;
		ll izq = get(a, c, 2*n, a, c);
		
		if(izq>cur) return find(2*n,a,c,cur);
		else return find(2*n+1,c,b,cur);
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

RMQ stm; 
RMQ stp; 

bool solve(vector<ll> arr){
	arr.pb(INF);
	int n = sz(arr);
	
	stm.init(n);
	forn(i,n) stm.set(i,arr[i]);
	
	
	stp.init(n);
	vector<ll> pref(n+1);
	forr(i,1,sz(pref)) pref[i] = pref[i-1]+arr[i-1];
	forr(i,1,sz(pref)) stp.set(i-1,pref[i]);
	
	forn(i,n-1){
		int r = stm.find(1,0,stm.sz,arr[i]);
		
		if(stp.get(i,r)>pref[i+1]) return false;
		stm.set(i,LLONG_MIN);
	}
	
	return true;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t; cin >> t;
	forn(T,t){
		ll n; cin >> n;
		vector<ll> arr(n); forn(i,n) cin >> arr[i];
		
		bool ok = solve(arr);
		reverse(arr.begin(),arr.end());
		ok &= solve(arr);
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
		
	}
	
	return 0;
}




