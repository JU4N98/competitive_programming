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
vector<bool> visi;
vector<vector<int>> g;

void dfs(int u){
	visi[u]=true;
	forn(i,sz(g[u])) if(!visi[g[u][i]]) dfs(g[u][i]);
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	g.resize(n);
	visi.resize(n,false);
	forn(i,m){
		int u,v; cin >> u >> v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	visi[n-1]=true;
	dfs(n-2);
	forn(i,n){
		if(i==n-1) cout << "A";
		else if(visi[i]) cout << "B";
		else cout << "A";
	}
	cout << "\n";
	
	
	return 0;
}




