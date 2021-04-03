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
vector<ll> id,sz;
ll cycles=0;

ll find(ll u){
	ll root=u;
	while(root!=id[root]) root=id[root];
	while(u!=root){
		ll next=id[u];
		id[u]=root;
		u=next;
	}
	return root;
}

void uf(ll u, ll v){
	ll r1=find(u), r2=find(v);
	if(r1==r2) cycles++;
	else{
		if(sz[r1]<sz[r2]){
			sz[r2]+=sz[r1];
			id[r1]=r2;
		}else{
			sz[r1]+=sz[r2];
			id[r2]=r1;
		}
	}
}

int main()
{
	// agregar g++ -DANARAP en compilacion
	#ifdef ANARAP
		freopen("input", "r", stdin);
		//freopen("output","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	forn(T,t){
		ll n,m,loops=0;
		cin>>n>>m;
		vector<pair<ll,ll>> edges;
		id.resize(n);
		sz.resize(n,1);
		forn(i,n) id[i]=i;
		forn(i,m){
			ll a,b;
			cin>>a>>b;
			a--,b--;
			
			if(a!=b){
				edges.pb({a,b});
			}else{
				loops++;
			}
		}
		forn(i,edges.size()){
			uf(edges[i].fst,edges[i].snd);
		}
		cout<<m-loops+cycles<<endl;
		cycles=0;
		id.clear();
		sz.clear();
		edges.clear();
	}
	
	return 0;
}

