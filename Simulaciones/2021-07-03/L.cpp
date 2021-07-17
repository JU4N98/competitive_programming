#include <bits/stdc++.h>
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

#ifdef ANARAP
#define MAXN 1000
#else
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

typedef ii tipo;
const ll MOD[2]={999727999,1070777777};
const ll P=1777771;
ll vp[MAXN][2];

tipo operacion(tipo a, tipo b)
{
	return {(a.fst+b.fst)%MOD[0], (a.snd+b.snd)%MOD[1]};
}

const tipo neutro={0,0};
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
}; //Use: definir operacion tipo neutro y MAXN,
//cin >> n; rmq.init(n); forn(i, n) cin >> rmq[i]; rmq.updall();

vector<vector<int>> g1,g2;
RMQ st1, st2;
map<ii,int> m1,m2;
int n;

void dfs(int node, int p, vector<vector<int>> &g, map<ii,int> &m)
{
	if(node != p)
	{
		ii a = st1.get(1,n+1), b = st2.get(1, n+1);
		//cout << node << ' ' << p << ' ' << a.fst+(a.snd << 32) << ' ' << b.fst+(b.snd << 32) << endl;
		ll ha = a.fst+(a.snd << 32), hb = b.fst+(b.snd << 32);
		m[mp(min(ha,hb), max(ha,hb))]++;
	}
	st1.set(node, neutro);
	st2.set(node, {vp[node][0], vp[node][1]});
	forall(it, g[node]) if(p != *it) dfs(*it, node, g, m);
	st2.set(node, neutro);
	st1.set(node, {vp[node][0], vp[node][1]});
	return;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vp[0][0] = vp[0][1] = 1;
	forn(k,2) forr(i,1,n+1) vp[i][k] = vp[i-1][k]*P%MOD[k];
	g1 = vector<vector<int>>(n+1);
	g2 = vector<vector<int>>(n+1);
	forn(i,n-1)
	{
		int a,b;
		cin >> a >> b;
		g1[a].pb(b);
		g1[b].pb(a);
	}
	forn(i,n-1)
	{
		int a,b;
		cin >> a >> b;
		g2[a].pb(b);
		g2[b].pb(a);
	}
	//cout << "g1\n";
	bool found = false;
	forr(k,1,n+1) if(sz(g1[k]) == 1)
	{
		found = true;
		st1.init(n+1);
		forr(i,1,n+1) st1[i] = {vp[i][0], vp[i][1]};
		st1.updall();
		st2.init(n+1);
		dfs(k,k,g1,m1);
		break;
	}
	assert(found);
	found = false;
	//cout << "g2\n";
	forr(k,1,n+1) if(sz(g2[k]) == 1)
	{
		found = true;
		st1.init(n+1);
		forr(i,1,n+1) st1[i] = {vp[i][0], vp[i][1]};
		st1.updall();
		st2.init(n+1);
		dfs(k,k,g2,m2);
		break;
	}
	assert(found);
	
	int ans = 0;
	forall(it,m1) if(m2.count(it->fst)) ans = (ans+m2[it->fst])%1000000007;
	if(ans <= 0)
	{
		bool special = false;
		forr(i,1,n+1)
		{
			if(sz(g1[i])+sz(g2[i]) <= 2) special = true;
			if(sz(g1[i])+sz(g2[i]) == 3) ans++;
		}
		if(special) cout << "2 0\n";
		else cout << "3 " << ans << '\n';
	}
	else cout << "2 " << ans << '\n';
	return 0;
}
