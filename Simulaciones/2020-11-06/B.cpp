#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define dbg(x) cerr<<#x<<"="<<x<<endl;
#define pb push_back
#define fst first
#define snd second
#define ll long long
//#define ANARAP
vector<vector<ll>> graf;
vector<ll> deg;
vector<bool> visi;
ll acum;

ll dfs(ll u){
	ll aux=1;
	forn(i,graf[u].size()){
		ll v=graf[u][i];
		deg[v]--;
		if(deg[v]==0 && !visi[v]){
			visi[v]=true;
			aux+=dfs(v);
		}
	}
	return aux;
}

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	ll n,m;
	while(cin>>n){
		cin>>m;
		graf.resize(n);
		deg.resize(n,0);
		visi.resize(n,false);
		
		forn(i,m){
			ll a,b;
			cin>>a>>b;
			a--;b--;
			graf[a].pb(b);
			deg[b]++;
		}
		forn(i,n) deg[i]++;
		
		vector<ll> orden(n);
		forn(i,n) cin>>orden[i];
		
		acum=0;
		forn(i,n){
			deg[orden[i]-1]--;
			if(!visi[orden[i]-1] && deg[orden[i]-1]==0){
				visi[orden[i]-1]=true;
				acum+=dfs(orden[i]-1);
			}
			cout<<acum<<"\n";
		}
		graf.clear();
		visi.clear();
		deg.clear();
	}
}
