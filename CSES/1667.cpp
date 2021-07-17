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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n);
	forn(i,m){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<int> dad(n,-1);
	queue<int> q;
	q.push(0);
	dad[0]=0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		forn(i,sz(g[u])){
			int v = g[u][i];
			if(dad[v]==-1){
				dad[v]=u;
				q.push(v);
			}
		}
	}
	if(dad[n-1]==-1){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	vector<int> ans;
	int u = n-1;
	while(dad[u]!=u){
		ans.pb(u);
		u=dad[u];
	}
	cout<<sz(ans)+1<<"\n";
	cout<<"1 ";
	dforn(i,sz(ans)) cout<<ans[i]+1<<" ";
	cout<<"\n";
	
	return 0;
}




