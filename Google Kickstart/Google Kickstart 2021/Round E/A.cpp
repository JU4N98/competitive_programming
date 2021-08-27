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

struct Edge {
	int u, v;
	ll cap, flow;
	Edge() {}
	Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
	int N;
	vector<Edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;
	Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {} //clear and init
	void addEdge(int u, int v, ll cap)
	{
		if (u != v)
		{
			E.emplace_back(Edge(u, v, cap));
			g[u].emplace_back(E.size() - 1);
			E.emplace_back(Edge(v, u, 0));
			g[v].emplace_back(E.size() - 1);
		}
	}
	bool BFS(int S, int T)
	{
		queue<int> q({S});
		fill(d.begin(), d.end(), N + 1);
		d[S] = 0;
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			if (u == T) break;
			for (int k: g[u])
			{
				Edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1)
				{
					d[e.v] = d[e.u] + 1;
					q.emplace(e.v);
				}
			}
		}
		return d[T] != N + 1;
	}
	ll DFS(int u, int T, ll flow = -1)
	{
		if (u == T || flow == 0) return flow;
		for (int &i = pt[u]; i < g[u].size(); ++i)
		{
			Edge &e = E[g[u][i]];
			Edge &oe = E[g[u][i]^1];
			if (d[e.v] == d[e.u] + 1)
			{
				ll amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (ll pushed = DFS(e.v, T, amt))
				{
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	ll maxFlow(int S,int T) //O(V^2*E), unit nets: O(sqrt(V)*E)
	{
		ll total = 0;
		while(BFS(S, T))
		{
			fill(pt.begin(), pt.end(), 0);
			while (ll flow = DFS(S, T)) total += flow;
		}
		return total;
	}
};

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin>>t;
	forn(T,t){
		string s; cin>>s;
		vector<int> cant(26);
		forn(i,sz(s)) cant[s[i]-'a']++;
		Dinic d = Dinic(54);
		forn(i,26){
			d.addEdge(52,i,cant[i]);
			d.addEdge(i+26,53,cant[i]);
			forn(j,26){
				if(i!=j){
					d.addEdge(i,j+26,cant[i]);
				}
			}
		}
		ll mf = d.maxFlow(52,53);
		//cout<<mf<<endl;
		if(mf!=sz(s)) cout<<"Case #"<<T+1<<": IMPOSSIBLE\n";
		else{
			forn(i,sz(s)){
				forn(j,sz(d.E)){
					if(d.E[j].u==s[i]-'a' && d.E[j].v>=26 && d.E[j].v<52 && d.E[j].flow!=0){
						d.E[j].flow--;
						//cout<<char(d.E[j].u+'a')<<" "<<char(d.E[j].v-26+'a')<<endl;
						s[i]=char(d.E[j].v-26+'a');
						break;
					}
				}
				
			}
			cout<<"Case #"<<T+1<<": "<<s<<"\n";
		}
	}
	
	return 0;
}




