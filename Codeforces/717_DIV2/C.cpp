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

struct Edge{
	int u,v;
	ll cap,flow;
	Edge(){}
	Edge(int u, int v, ll cap): u(u),v(v),cap(cap),flow(0){}
};

struct Dinic{
	int N;
	vector<Edge> E;
	vector<vector<int>> g;
	vector<int> d,pt;
	Dinic(int N): N(N), E(0),g(N),d(N),pt(N){};
	void addEdge(int u, int v, ll cap){
		if(u!=v){
			E.emplace_back(Edge(u,v,cap));
			g[u].emplace_back(E.size()-1);
			E.emplace_back(Edge(v,u,0));
			g[v].emplace_back(E.size()-1);
		}
	}
	bool BFS(int S, int T){
		queue<int> q({S});
		fill(d.begin(),d.end(),N+1);
		d[S]=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			if(u==T) break;
			for(int k:g[u]){
				Edge &e=E[k];
				if(e.flow <e.cap && d[e.v]>d[e.u]+1){
					d[e.v]=d[e.u]+1;
					q.emplace(e.v);
				}
			}
		}
		return d[T]!=N+1;
	}
	ll DFS(int u,int T, ll flow=-1){
		if(u==T || flow==0) return flow;
		for(int &i=pt[u];i<g[u].size();++i){
			Edge &e = E[g[u][i]];
			Edge &oe = E[g[u][i]^1];
			if(d[e.v]==d[e.u]+1){
				ll amt=e.cap-e.flow;
				if(flow!=-1 && amt>flow) amt=flow;
				if(ll pushed=DFS(e.v,T,amt)){
					e.flow+=pushed;
					oe.flow-=pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	ll maxFlow(int S, int T){
		ll total=0;
		while(BFS(S,T)){
			fill(pt.begin(),pt.end(),0);
			while(ll flow =DFS(S,T)) total+=flow;
		}
		return total;
	}
};

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin>>n;
	vector<ll> arr(n);
	ll sum=0;
	forn(i,n){
		cin>>arr[i];
		sum+=arr[i];
	}
	if(sum%2==1) cout<<"0\n";
	else{
		Dinic d=Dinic(n+4);
		forn(i,n){
			d.addEdge(0,i+1,arr[i]);
			d.addEdge(i+1,n+1,arr[i]);
			d.addEdge(i+1,n+2,arr[i]);
		}
		d.addEdge(n+1,n+3,sum/2);
		d.addEdge(n+2,n+3,sum/2);
		ll total = d.maxFlow(0,n+3);
		if(total<sum) cout<<"0\n";
		else{
			ll mini=0;
			forn(i,n){
				if(arr[i]<arr[mini]) mini=i;
			}
			cout<<"1\n";
			cout<<mini+1<<"\n";
		}
	}
	return 0;
}




