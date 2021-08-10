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

#define MAXN 200000
vector<int> G[MAXN],gt[MAXN]; //Limpiar si se corre mas de una vez
//nodos 0...N-1 ; componentes 0...cantcomp-1
int comp[MAXN],N,cantcomp,used[MAXN];
stack<int> pila;
void add(int a, int b){ G[a].pb(b);gt[b].pb(a);}
void dfs1(int nodo)
{
	used[nodo]=1;
	forall(it,G[nodo]) if(!used[*it]) dfs1(*it);
	pila.push(nodo);
}
void dfs2(int nodo)
{
	used[nodo]=2;
	comp[nodo]=cantcomp-1;
	forall(it,gt[nodo]) if(used[*it]!=2) dfs2(*it);
}
void kosaraju()
{
	cantcomp=0;
	memset(used,0,sizeof(used));
	forn(i,N) if(!used[i]) dfs1(i);
	while(!pila.empty())
	{
		if(used[pila.top()]!=2)
		{
			cantcomp++;
			dfs2(pila.top());
		}
		pila.pop();
	}
}

vector<vector<ll>> g;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m; cin>>n>>m;
	g.resize(n); N=n;
	forn(i,m){
		ll a,b; cin>>a>>b;a--,b--;
		g[a].pb(b); g[b].pb(a);
		add(a,b);
	}
	kosaraju();
	forn(i,n) cout<<comp[i]<<" ";
	cout<<"\n";
	
	
	return 0;
}




