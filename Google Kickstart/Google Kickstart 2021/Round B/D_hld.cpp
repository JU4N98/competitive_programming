#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(ll i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((ll)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP
#define operacion(x,y) __gcd(x,y)

#ifdef ANARAP
	#define MAXN 60000
#else
	#define MAXN 60000
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef ll tipo;
const tipo neutro=0;
vector<pair<ll,ii>> ver;
map<ii,ii> m;

struct RMQ{
	ll sz;
	tipo t[4*MAXN];
	tipo &operator[](ll p){return t[sz+p];}
	void init(ll n){
		sz=1<<(32-__builtin_clz(n));
		forn(i,2*sz) t[i]=neutro;
	}
	void updall() {dforn(i,sz) t[i]=operacion(t[2*i],t[2*i+1]);}
	tipo get(ll i, ll j) {return get(i,j,1,0,sz);}
	tipo get(ll i, ll j, ll n, ll a, ll b){
		if(j<=a || i>=b) return neutro;
		if(i<=a && b<=j) return t[n];
		ll c=(a+b)/2;
		return operacion(get(i,j,2*n,a,c),get(i,j,2*n+1,c,b));
	}
	void set(ll p, tipo val){
		p+=sz;
		while(p>0 && t[p]!=val){
			t[p]=val;
			p/=2;
			val=operacion(t[p*2],t[p*2+1]);
		}
	}
};

vector<ll> g[MAXN];
ll wg[MAXN],dad[MAXN],dep[MAXN];

void dfs1(ll x){
	wg[x]=1;
	for(ll y: g[x]) if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y);
		wg[x]+=wg[y];
	}
}
ll curpos,pos[MAXN],head[MAXN];
void hld(ll x, ll c){
	if(c<0) c=x;
	if(dad[x]!=-1) ver.pb({m[{x,dad[x]}].fst,{m[{x,dad[x]}].snd,curpos}});
	pos[x]=curpos++;head[x]=c;
	ll mx=-1;
	for(ll y : g[x]) if(y!=dad[x] && (mx<0 || wg[mx]<wg[y])) mx=y;
	if(mx>=0) hld(mx,c);
	for(ll y: g[x]) if(y!=mx&&y != dad[x]) hld(y,-1);
}

void hld_init(){dad[0]=-1;dep[0]=0;dfs1(0);curpos=0;hld(0,-1);}

ll query(ll x, ll y, RMQ &st){
	ll r=neutro;
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]]) swap(x,y);
		r=operacion(r,st.get(pos[head[y]],pos[y]+1));
		y=dad[head[y]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	r=operacion(r,st.get(pos[x]+1,pos[y]+1));
	return r;
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
		forn(i,n-1){
			ll u,v,li,ai;
			cin>>u>>v>>li>>ai;
			u--;v--;
			m[{u,v}]={li,ai};
			m[{v,u}]={li,ai};
			g[u].pb(v);
			g[v].pb(u);
		}
		RMQ st;
		st.init(n);
		
		hld_init();
		
		sort(ver.begin(),ver.end());
		vector<pair<ll,ii>> queries;
		forn(i,q){
			ll c,w;
			cin>>c>>w;
			queries.pb({w,{c-1,i}});
		}
		
		sort(queries.begin(),queries.end());
		ll pos=0;
		vector<ll> ans(q);
		//cout<<"VERTEX"<<endl;
		//forn(i,ver.size()) cout<<"["<<ver[i].fst<<"["<<ver[i].snd.fst<<","<<ver[i].snd.snd<<"]], ";
		//cout<<endl;
		//cout<<"QUERIES"<<endl;
		//forn(i,queries.size()) cout<<"["<<queries[i].fst<<"["<<queries[i].snd.fst<<","<<queries[i].snd.snd<<"]], ";
		//cout<<endl;
		forn(i,q){
			ll iq=queries[i].snd.snd,w=queries[i].fst,c=queries[i].snd.fst;
			while(pos<n-1 && ver[pos].fst<=w){
				//cout<<pos<<endl;
				ll idx=ver[pos].snd.snd, a=ver[pos].snd.fst;
				st.set(idx,a);
				pos++;
			}
			//cout<<st.get(0,n)<<endl;
			ans[iq]=query(0,c,st);
			//cout<<"idx "<<iq<<" ans "<<ans[iq]<<endl;
		}
		cout<<"Case #"<<T+1<<": ";
		forn(i,q) cout<<ans[i]<<" ";
		cout<<"\n";
		ver.clear();
		m.clear();
		forn(i,n) g[i].clear();
	}
	
	return 0;
}




