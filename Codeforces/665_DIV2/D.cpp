#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<(x)<<endl;
#define forr(a,b,c) for(int a=b; a<c; a++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define ll long long
#define MOD 1000000007
//#define ANARAP

vector<vector<ll>> graf;
vector<bool> visited;
vector<ll> producto;
vector<ll> factores;
ll n;

ll dfs(ll u){
	ll answ=1;
	forn(i,graf[u].size()){
		ll v=graf[u][i];
		if(!visited[v]){
			visited[v]=true;
			ll answp=dfs(v);
			producto.pb((n-answp)*answp);
			answ+=answp;
		}
	}
	return answ;
}

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	ll t;
	cin>>t;
	forn(i,t){
		
		cin>>n;
		visited.resize(n,false);
		graf.resize(n);
		forn(j,n-1){
			ll a,b;
			cin>>a>>b;
			a--;b--;
			graf[a].pb(b);
			graf[b].pb(a);
		}
		ll m;
		cin>>m;
		factores.resize(m,0);
		forn(j,m) cin>>factores[j];
		visited[0]=true;
		dfs(0);
		
		sort(factores.begin(),factores.end(),greater<ll>());
		sort(producto.begin(),producto.end(),greater<ll>());
		ll des=1;
		ll aux=factores[0];
		while(m>n-1){
			aux=(aux*factores[des])%MOD;
			factores[des]=aux;
			des++;
			m--;
		}
		des--;
		ll ans=0;
		n=producto.size();
		
		forn(j,min(n,m)){
			ans = ((ans%MOD) + ((factores[j+des]%MOD)*(producto[j]%MOD))%MOD)%MOD;
		}
		forr(j,min(n,m),n){
			ans = ((ans%MOD)+producto[j]%MOD)%MOD;
		}
		
		cout<<ans<<"\n";
		
		visited.clear();
		producto.clear();
		graf.clear();
		visited.clear();
	}
	
	return 0;
}
