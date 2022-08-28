#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	forn(T,t){
		int n, m; cin >> n >> m;
		vector<int> frens(n), un(n);
		vector<vector<int>> g(n);
		forn(i,n) cin >> un[i];
		forn(i,m){
			int u,v; cin >> u >> v; u--,v--;
			frens[u]++;
			frens[v]++;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		//~ forn(i,n) cout << frens[i] << " ";
		//~ cout << endl;
		
		if(m%2 == 0) cout << "0\n";
		else{
			int ans = INT_MAX, sum = 0; 
			forn(i,n){
				sum+= un[i];
				if(frens[i]%2 == 1) ans = min(ans,un[i]);
				forn(j,sz(g[i])){
					int k = g[i][j];
					if(frens[i]%2 == 0 && frens[k]%2 == 0) ans = min(ans,un[i]+un[k]);
				}
			}
			
			if(ans == INT_MAX) cout << sum << "\n";
			else cout << ans << "\n";
		}
	}
	
	return 0;
}




