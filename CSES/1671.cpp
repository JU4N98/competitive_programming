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
typedef pair<ll,ll> ii;

#define INF 1e18
ll N;
#define MAX_V 200010
vector<ii> G[MAX_V];

#define add(a, b, w) G[a].pb(make_pair(w, b))
void dijkstra(int s){
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	vector<ll> dist(N, INF); vector<int> dad(N, -1);
	Q.push(make_pair(0, s)); dist[s] = 0;
	while(sz(Q)){
		ii p = Q.top(); Q.pop();
		if(dist[p.snd]!=p.fst) continue;
		forall(it, G[p.snd])
			if(dist[p.snd]+it->first < dist[it->snd]){
				dist[it->snd] = dist[p.snd] + it->fst;
				dad[it->snd] = p.snd;
				Q.push(make_pair(dist[it->snd], it->snd));	
			}
	}
	forn(i,sz(dist)) cout<<dist[i]<<" ";
	cout<<"\n";
	//~ if(dist[t]<INF)//path generator
		//~ for(int i=t; i!=-1; i=dad[i])
			//~ printf("%d%c", i, (i==s?'\n':' '));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m;
	cin>>n>>m;
	forn(i,m){
		ll u,v,c;
		cin>>u>>v>>c;
		u--;v--;
		add(u,v,c);
	}
	N=n;
	dijkstra(0);
	
	
	return 0;
}




