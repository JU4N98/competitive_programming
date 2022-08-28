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

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	forn(T,t){
		int r, c; cin >> r >> c;
		
		vector<bool> man(r*c), tree(r*c);
		vector<string> ans(r);
		
		forn(i,r){
			string row; cin >> row;
			ans[i] = row;
			forn(j,c){
				man[i*c+j] = row[j] == '^';
				tree[i*c+j] = row[j] != '#';
				if(tree[i*c+j]) ans[i][j] = '^';
			}
		}
		
		vector<int> deg(r*c);
		vector<vector<int>> graph(r*c);
		forn(i,r){
			forn(j,c){
				if(!tree[i*c+j]) continue;
				
				forn(k,4){
					int nr = i+dr[k], nc = j+dc[k];
					if(nr>-1 && nr<r && nc>-1 && nc<c && tree[nr*c+nc]){
						graph[i*c+j].pb(nr*c+nc);
						deg[i*c+j]++;
					}
				}
			}
		}
		
		bool ok = true;
		
		vector<bool> visi(r*c);
		queue<int> q; 
		forn(i, r*c){
			if(deg[i]<2 && tree[i]){
				q.push(i);
				visi[i] = true;
				ok &= !man[i];
				ans[i/c][i%c] = '.';
			}
		}
		
		while(!q.empty()){
			int u = q.front(); q.pop();
			
			forn(i,sz(graph[u])){
				int v = graph[u][i];
				deg[v]--;
				if(deg[v] < 2 && !visi[v]){
					q.push(v);
					visi[v] = true;
					ok &= !man[v];
					ans[v/c][v%c] = '.';
				}
			}
		}
		
		if(!ok) cout << "Case #" << T+1 << ": Impossible\n";
		else{
			cout << "Case #" << T+1 << ": Possible\n";
			forn(i,r){
				cout << ans[i] << "\n";
			}
		}
	}
	
	return 0;
}




