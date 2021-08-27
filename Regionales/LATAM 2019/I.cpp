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
const int mod = 1000000007;
vector<vector<int>> G;
vector<int> dp;
vector<bool> visi;

int dfs(int u){
	visi[u]=true;
	forn(i,sz(G[u])){
		int v = G[u][i];
		if(!visi[v]) dfs(v);
		dp[u]=((dp[u]+dp[v])%mod+mod)%mod;
	}
	return dp[u];
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,l; cin>>n>>l;
	G.resize(n);
	dp.resize(n);
	visi.resize(n);
	forn(i,l){
		int k; cin>>k;
		forn(j,k){
			int v; cin>>v;
			G[i].pb(v-1);
		}
	}
	forr(i,l,n) dp[i]=1;
	int ans1=dfs(0), ans2=0;
	forr(i,l,n) if(visi[i]) ans2++;
	cout<<ans1<<" "<<ans2<<"\n";
	
	return 0;
}




