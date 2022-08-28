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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
bool ok = true;
vector<vector<int>> g;
vector<bool> visi, color;


void dfs(int u){
	forn(i,sz(g[u])){
		int v = g[u][i];
		if(!visi[v]){
			color[v] = !color[u];
			visi[v] = true;
			dfs(v);
		}else{
			if(color[v] == color[u]) ok = false;
		}
	}
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n, m, p; cin >> n >> m >> p;
	
	g.resize(n);
	visi.resize(n);
	color.resize(n);
	
	forn(M,m){
		int u,v; cin >> u >> v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	int count = 0;
	forn(i,n){
		if(!visi[i]){
			count++;
			visi[i] = true;
			color[i] = true;
			dfs(i);
		}
	}
	
	if(!ok) cout << "impossible\n";
	else{
		ll ans = 1;
		forn(i,count-1) ans = (ans*2LL)%p;
		cout << (ans+1)%p << "\n";
	}
	
	return 0;
}




