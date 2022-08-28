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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
bool shop[51][51];
bool visi[51][51][105];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

struct state{
	int r,c,f,step;
	state(int ri, int ci, int fi, int stepi){ r=ri, c=ci, f=fi, step=stepi;}
	void print(){cout << r << " " << c << " " << f << "\n";}
};

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int r,c,f,s; cin >> r >> c >> f >> s;
	
	forn(i,r) forn(j,c) shop[i][j] = false;
	forn(i,r) forn(j,c) forn(k,f+1) visi[i][j][k] = false;
	
	forn(i,s){
		int ri,ci; cin >> ri >> ci; ri--; ci--;
		shop[ri][ci] = true;
	}
	
	int ans = -1;
	queue<state> q; q.push(state(0,0,f,0));
	visi[0][0][f] = true;
	while(!q.empty() && ans == -1){
		state act = q.front(); q.pop();
		
		if(ans == -1 && act.r == r-1 && act.c == c-1) ans = act.step;
		if(act.f == 0) continue;
		
		forn(i,4){
			int nr = act.r + dx[i], nc = act.c + dy[i], nf = shop[nr][nc] ? f: act.f - 1;
			if(nr>-1 && nr<r && nc>-1 && nc<c && !visi[nr][nc][nf]){
				visi[nr][nc][nf] = true;
				q.push(state(nr,nc,nf,act.step+1));
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}




