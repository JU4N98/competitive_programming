#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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
typedef pair<ll,ll> ii;
vector<vector<ll>> g;
vector<ll> cant;
vector<ll> dad;
vector<bool> white;

void dfs1(ll d, ll u){
	white[u] = !white[d];
	
	forn(i,sz(g[u])){
		ll v = g[u][i];
		if(v != d) dfs1(u,v);
	}
}

ll dfs2(ll d, ll u){
	dad[u] = d;
	cant[u] = 1;
	forn(i,sz(g[u])){
		ll v = g[u][i];
		if(v != d) cant[u] += dfs2(u,v);
	}
	
	return cant[u];
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	g.resize(n);
	dad.resize(n+1,0);
	cant.resize(n+1,0);
	white.resize(n+1,false);
	forn(i,n-1){
		int u, v; cin >> u >> v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
	
	dfs1(n,0);
	
	dfs2(n,0);
	
	ll sum = 0;
	forn(u,n){
		forn(j,sz(g[u])){
			ll v = g[u][j];
			if(v == dad[u]) sum += (n-cant[u])*cant[u];
			if(u == dad[v]) sum += (n-cant[v])*cant[v];
		}
	}
	
	ll wcount = 0;
	forn(i,n) if(white[i]) wcount++;
	
	cout << ((sum/2) + (wcount*(n-wcount)))/2 << endl;
	
	
	return 0;
}




