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
	#define MAXN 1000
#else
	#define MAXN 500000
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
const ll MOD = 1000000007;

ll mulMod(ll a,ll b,ll m=MOD){
	ll x=0, y=a%m;
	while(b>0)
	{
		if(b%2==1) x=(x+y)%m;
		y=(y*2)%m;
		b/=2;
	}
	return x%m;
}

ll expMod(ll b,ll e,ll m=MOD){
	if(!e) return 1;
	ll q=expMod(b,e/2,m);
	q=mulMod(q,q,m);
	return e%2? mulMod(b,q,m) : q;
}

vector<int> G[MAXN],gt[MAXN];
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

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll fact[500000];
	fact[0]=1;
	forr(i,1,500000) fact[i]=((fact[i-1]%MOD)*(i%MOD))%MOD;
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		vector<ll> a(n),b(n);
		map<ll,ll> m;
		forn(i,n) cin>>a[i];
		forn(i,n) cin>>b[i];
		N=n;
		forn(i,n){
			if(m.find(a[i])!=m.end()){
				add(m[a[i]],i);
			}else m[a[i]]=i;
			if(m.find(b[i])!=m.end()){
				add(i,m[b[i]]);
			}else m[b[i]]=i;
		}
		
		kosaraju();
		forn(i,n) if(a[i]==b[i]) cantcomp--;
		cout<<expMod(2,cantcomp)%MOD<<"\n";
		forn(i,n){G[i].clear();gt[i].clear();}
	}
	
	return 0;
}




