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
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	vector<int> color(n);
	forn(i,n) color[i]=-1;
	queue<int> q;
	
	bool ans=true;
	forn(j,n) if(color[j]==-1){
		q.push(j);
		color[j]=0;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			forn(i,sz(g[u])){
				int v = g[u][i];
				if(color[v]==-1){
					color[u]==0? color[v]=1 : color[v]=0;
					q.push(v);
				}else{
					ans = ans && color[u]!=color[v];
				}
			}
		}
	}
	
	if(!ans){
		cout<<"IMPOSSIBLE\n";
	}else{
		forn(i,sz(color)) cout<<color[i]+1<<" ";
		cout<<"\n"; 
	}
	
	return 0;
}




