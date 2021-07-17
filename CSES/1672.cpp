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
#define MAX_N 501
#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
const long long INF = 1000000000000000000;

ll N;
ll G[MAX_N][MAX_N];
void floyd(){
	forn(k, N) forn(i, N) if(G[i][k]!=INF) forn(j, N) if(G[k][j]!=INF)
	G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m,q;
	cin>>n>>m>>q;
	N=n;
	forn(i,n) forn(j,n) G[i][j]=INF;
	forn(i,n) G[i][i]=0;
	forn(i,m){
		ll u,v,c;
		cin>>u>>v>>c;
		u--;v--;
		G[u][v]=min(c,G[u][v]);
		G[v][u]=min(c,G[v][u]);
	}
	
	floyd();
	
	forn(i,q){
		int u,v;
		cin>>u>>v;
		u--;v--;
		if(G[u][v]==INF) cout<<"-1\n";
		else cout<<G[u][v]<<"\n";
	}
	
	return 0;
}




