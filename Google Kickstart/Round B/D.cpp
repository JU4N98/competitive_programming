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
vector<vector<pair<ll,pair<ll,ll>>>> g;
vector<bool> visi;
ll ans,w;
bool sol=true;

void dfs(ll u, ll t, ll gcd){
	visi[u]=true;
	forn(i,g[u].size()){
		ll v=g[u][i].fst,l=g[u][i].snd.fst,a=g[u][i].snd.snd;
		if(visi[v]) continue;
		if(t==v){
			if(gcd==0 && w>=l) ans=a;
			else if(gcd!=0 && w>=l) ans=__gcd(a,gcd);
			else{
				ans=gcd;
			}
		}
		if(gcd==0 && w>=l) dfs(v,t,a);
		if(gcd==0 && w<l) dfs(v,t,gcd);
		if(gcd!=0 && w>=l) dfs(v,t,__gcd(a,gcd));
		if(gcd!=0 && w<l) dfs(v,t,gcd);
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
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,q;
		cin>>n>>q;
		g.resize(n);
		visi.resize(n,false);
		forn(i,n-1){
			ll x,y,l,a;
			cin>>x>>y>>l>>a;
			g[x-1].pb({y-1,{l,a}});
			g[y-1].pb({x-1,{l,a}});
		}
		cout<<"Case #"<<T+1<<": ";
		forn(i,q){
			ll c;
			cin>>c>>w;
			dfs(0,c-1,0);
			cout<<ans<<" ";
			forn(j,n) visi[j]=false;
		}
		g.clear();
		visi.clear();
		cout<<"\n";
	}
	
	
	return 0;
}




