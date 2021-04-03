#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define ll long long
//#define ANARAP
vector<vector<ll>> graf;
vector<ll> dfs_num, dfs_low, visi, st;
ll dfs_count=0, ans=0;

void tarjan(ll u){
	dfs_low[u]=dfs_num[u]=dfs_count++;
	st.pb(u);
	visi[u]=1;
	
	forn(i,graf[u].size()){
		ll v=graf[u][i];
		if(dfs_num[v]==-1) tarjan(v);
		if(visi[v]) dfs_low[u]=min(dfs_low[v],dfs_low[u]);
	}
	
	if(dfs_low[u]==dfs_num[u]){
		ll count = 0;
		while(1){
			ll v = st.back(); st.pop_back(); visi[v]=0;
			count++;
			if(u==v) break;
		}
		if(count>1) ans+=count;
	}
}

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		string s;
		cin>>n;
		cin>>s;
		graf.resize(n);
		dfs_low.resize(n,0);
		dfs_num.resize(n,-1);
		visi.resize(n,0);
		forn(j,n){
			switch(s[j]){
				case '-':
					graf[j].pb((j+1)%n);
					graf[(j+1)%n].pb((j)%n);
				break;
				case '<':
					graf[(j+1)%n].pb(j);
				break;
				case '>':
					graf[j].pb((j+1)%n);
				break;
			}
		}
		
		forn(j,n) if(dfs_num[j]==-1) tarjan(j);
		
		cout<<ans<<"\n";
		
		dfs_count=0; ans=0;
		graf.clear();
		dfs_low.clear();
		dfs_num.clear();
		visi.clear();
		st.clear();
	}
	
	return 0;
} 
