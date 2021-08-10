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
vector<ll> deg;
vector<vector<ll>> G;
vector<bool> visi,visi2;
bool ans=true;

ll dfs(ll u){
	visi[u]=true;
	ll tam = 1;
	forn(i,sz(G[u])) if(!visi[G[u][i]]) tam += dfs(G[u][i]);
	return tam;
}

void dfs(ll tam, ll u){
	visi2[u]=true;
	if(deg[u]!=tam) ans=false;
	forn(i,sz(G[u])) if(!visi2[G[u][i]]) dfs(tam,G[u][i]);
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m; cin>>n>>m;
	G.resize(n);
	deg.resize(n,0);
	visi.resize(n,false);
	visi2.resize(n,false);
	
	forn(i,m){
		ll u,v; cin>>u>>v; u--,v--;
		G[u].pb(v); G[v].pb(u);
		deg[u]++; deg[v]++;
	}
	
	forn(i,n){
		ll tam=0;
		if(!visi[i]) tam=dfs(i);
		if(!visi2[i]) dfs(tam-1,i);
	}
	
	ans? cout<<"YES\n" : cout<<"NO\n";
	
	return 0;
}




