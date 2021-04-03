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
#define fst irst
#define snd second
#define ANARAP

#ifdef ANARAP
#define MAXN 2000
#else
#define MAXN 200010
#endif

#define INF MAXN

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int n,m,dp[MAXN][2][2][2],vp[MAXN],treedp[MAXN][2][2];
vector<int> g[MAXN];

void dfs(int node, int p)
{
	vp[node] = p;
	forall(it, g[node]) if(*it != p && *it >= n) dfs(*it, node);
}

int treesolve(int node, int prev, int must)
{
	if(treedp[node][prev][must] != -1) return treedp[node][prev][must];
	ll ret = INF;
	
	//put here
	ll aux = 1;
	forall(it, g[node]) if(*it != vp[node])
	{
		assert(*it >= n);
		aux += treesolve(*it, 1, 0);
	}
	ret = min(ret, aux);
	
	//do not put here
	if(!must)
	{
		ll aux = 0;
		forall(it, g[node]) if(*it != vp[node])
		{
			assert(*it >= n);
			aux += treesolve(*it, 0, 0);
		}
		if(prev) ret = min(ret, aux);
		//some child covers this one
		forall(it, g[node]) if(*it != vp[node])
		{
			ret = min(ret, aux - treesolve(*it, 0, 0) + treesolve(*it, 0, 1));
		}
	}
	
	return treedp[node][prev][must] = ret;
}

int startFrom(int node, bool put, bool need)
{
	if(treedp[node][put][need] != -1) return treedp[node][put][need];
	ll ret = INF;
	
	//put here
	if(put)
	{
		ll aux = 1;
		forall(it, g[node]) if(*it != vp[node] && *it >= n)
		{
			aux += treesolve(*it, 1, 0);
		}
		ret = min(ret, aux);
	}
	else
	{
		//some child covers this one
		if(need)
		{
			ll aux = 0;
			forall(it, g[node]) if(*it != vp[node] && *it >= n)
			{
				aux += treesolve(*it, 0, 0);
			}
			forall(it, g[node]) if(*it != vp[node] && *it >= n)
			{
				ret = min(ret, aux - treesolve(*it, 0, 0) + treesolve(*it, 0, 1));
			}
		}
		//cover not needed
		else
		{
			ll aux = 0;
			forall(it, g[node]) if(*it != vp[node] && *it >= n)
			{
				aux += treesolve(*it, 0, 0);
			}
			ret = min(ret, aux);
		}
	}
	//cout << node << " put=" << put << " need=" << need << ' ' << ret << '\n';
	return treedp[node][put][need] = ret;
}

int solve(int pos, bool prev, bool must, bool fst)
{
	if(pos == n)
	{
		if(must && !fst) return INF;
		return 0;
	}
	if(pos == 1) fst = prev;
	if(dp[pos][prev][must][fst] != -1) return dp[pos][prev][must][fst];
	int ret = INF;
	
	//put here
	ret = solve(pos+1, 1, 0, fst) + startFrom(pos, 1, 0);
	
	//do not put here
	if(!must)
	{
		//prev covers this one
		if(prev) ret = min(ret, solve(pos+1, 0, 0, fst) + startFrom(pos, 0, 0));
		else
		{
			//next covers this one
			ret = min(ret, solve(pos+1, 0, 1, fst) + startFrom(pos, 0, 0));
			//some child covers this one
			ret = min(ret, solve(pos+1, 0, 0, fst) + startFrom(pos, 0, 1));
		}
	}
	return dp[pos][prev][must][fst] = ret;
}

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	forn(i,n+m)
	{
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	forn(i,n) dfs(i,i);
	memset(dp, -1, sizeof(dp));
	memset(treedp, -1, sizeof(treedp));
	ll ans = solve(0, 0, 0, 0);
	assert(ans < INF);
	cout << ans << '\n';
	return 0;
}
