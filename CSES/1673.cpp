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
#define MAX_N 6000

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
ll const INF = LLONG_MAX;

ll N;
vector<ii> G[MAX_N];
ll dist[MAX_N];
void bford(int src){
	forn(i,N) dist[i]=INF;
	dist[src]=0;
	forn(i, N-1) forn(j, N) if(dist[j]!=INF) forall(it, G[j])
		dist[it->snd]=min(dist[it->snd], dist[j]+it->fst);
}

vector<bool> llego;
vector<vector<ll>> g;

bool hasNegCycle(){
	forn(j, N) if(dist[j]!=INF) forall(it, G[j])
		if(dist[it->snd]>dist[j]+it->fst && (llego[it->snd] || llego[j])) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m;
	cin>>n>>m;
	N=n;
	
	g.resize(n);
	forn(i,m){
		ll u,v,c;
		cin>>u>>v>>c;
		u--;v--;
		G[u].pb({-c,v});
		g[v].pb(u);
	}
	
	llego.resize(n,false);
	queue<ll> q;
	q.push(n-1);
	llego[n-1]=true;
	while(!q.empty()){
		ll u = q.front();
		q.pop();
		forn(i,sz(g[u])){
			ll v = g[u][i];
			if(!llego[v]){
				llego[v]=true;
				q.push(v);
			}
		}
	}
	
	bford(0);
	if(hasNegCycle()) cout<<"-1\n";
	else cout<<-dist[n-1]<<"\n";
	
	return 0;
}




