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
		int n; cin>>n;
		vector<vector<int>> g(n);
		vector<int> deg(n);
		forn(i,n){
			int k; cin>>k;
			forn(j,k){
				int chap; cin>>chap;
				g[chap-1].pb(i);
				deg[i]++;
			}
		}
		
		set<int> s;
		
		int cant=0;
		forn(i,n) if(deg[i]==0){s.insert(i);}
		
		vector<int> dist(n,0);
		set<int> sa,sa2;
		int ans=0;
		while(!s.empty()){
			int u = *(s.begin());
			s.erase(s.begin());
			cant++;
			forn(i,sz(g[u])){
				int v = g[u][i];
				deg[v]--;
				if(deg[v]==0){
					if(v<u){
						dist[v]=dist[u]+1;
						sa.insert(v);
					}else{
						dist[v]=dist[u];
						s.insert(v);
					}
					ans=max(ans,dist[v]);
				}
			}
			if(s.empty()){ s=sa; sa=sa2;}
		}
		
		if(cant<n) cout<<-1<<"\n";
		else cout<<ans+1<<"\n";
	}
	
	return 0;
}




