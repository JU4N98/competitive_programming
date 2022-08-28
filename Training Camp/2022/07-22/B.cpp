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
set<ii> visi;
map<ii,set<ii>> g;
int W,H,n;

int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
int dfs(int x, int y){
	int ans = 1;
	for(auto it = g[{x,y}].begin(); g[{x,y}].end() != it; it++){
		if(visi.find(*it) == visi.end()){
			ii v = *it;
			visi.insert(v);
			ans += dfs(v.fst,v.snd); 
		}
	}
	return ans;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> W >> H >> n;
	vector<pair<ii,ii>> line(n);
	
	forn(i,n) cin >> line[i].fst.fst >> line[i].fst.snd >> line[i].snd.fst >> line[i].snd.snd;
	
	forn(i,H){
		forn(j,W){
			forn(k,4){
				int nx = i+dx[k], ny = j+dy[k];
				if(nx>-1 && nx < H && ny > -1 && ny < W)
					g[{i,j}].insert({nx,ny});
			}
		}
	}
	
	forn(i,n){
		if(line[i].fst.fst == line[i].snd.fst){
			int xi = line[i].fst.fst;
			int mini = min(line[i].fst.snd, line[i].snd.snd);
			int maxi = max(line[i].fst.snd, line[i].snd.snd);
			forr(j,mini,maxi){
				g[{j,xi-1}].erase({j,xi});
				g[{j,xi}].erase({j,xi-1});
			}
		}else{
			int yi = line[i].fst.snd;
			int mini = min(line[i].fst.fst, line[i].snd.fst);
			int maxi = max(line[i].fst.fst, line[i].snd.fst);
			forr(j,mini,maxi){
				g[{yi-1,j}].erase({yi,j});
				g[{yi,j}].erase({yi-1,j});
			}
		}
	}
	
	vector<int> ans;
	forn(i,H){
		forn(j,W){
			if(visi.find({i,j}) == visi.end()){
				visi.insert({i,j});
				ans.pb(dfs(i,j));
			}
		}
	}
	
	sort(ans.begin(),ans.end());
	forn(i,sz(ans)) cout << ans[i] << " ";
	cout << "\n";
	
	return 0;
}




