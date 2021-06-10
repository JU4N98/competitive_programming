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
//#define ANARAP

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
vector<vector<ll>> g;
vector<bool> visi;
ll val[2][200010];
ll dp[2][200010];

ll dfs(ll valu, ll u,ll padre){
	if(dp[valu][u]==-1){
		dp[valu][u]=0;
		forn(i,sz(g[u])){
			ll v=g[u][i];
			if(v!=padre) dp[valu][u]+=max(abs(val[valu][u]-val[0][v])+dfs(0,v,u),abs(val[valu][u]-val[1][v])+dfs(1,v,u));
		}
	}
	return dp[valu][u];
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		g.resize(n);
		visi.resize(n,false);
		forn(i,n) cin>>val[0][i]>>val[1][i];
		forn(i,n-1){
			ll u,v;
			cin>>u>>v;
			u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		forn(i,2) forn(j,n) dp[i][j]=-1LL;
		dfs(0,0,-1);
		dfs(1,0,-1);
		//~ forn(i,2){
			//~ forn(j,n){
				//~ cout<<dp[i][j]<<" ";
			//~ }
			//~ cout<<endl;
		//~ }
		cout<<max(dp[0][0],dp[1][0])<<"\n";
		visi.clear();
		g.clear();
	}
	
	return 0;
}




