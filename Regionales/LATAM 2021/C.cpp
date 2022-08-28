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
#define x fst
#define y snd

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int pointTo(ii point){ // maps a point to its id
	return point.y*101+point.x;
}

int pointsTo(ii p1, ii p2){
	return  (p1.y!=p2.y? 10000: 0) + min(pointTo(p1),pointTo(p2));
}

bool check(ii point){ // checks if a point is into the grid
	return point.x>=0 && point.x<=100 && point.y>=0 && point.y<=100;
}

vector<vector<bool>> state; // represents the position of the clouds when it = 0
void update(vector<bool> &rea){
	vector<bool> ans(101*101);
	
	rea = ans;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x0,y0,xd,yd; cin >> x0 >> y0 >> xd >> yd;
	int n; cin >> n;
	vector<vector<ii>> cl(n); //clouds
	state.resize(n,vector<bool>(101*101));
	vector<ii> del(n); //delta
	forn(i,n){
		int v; cin >> v; char mov; cin >> mov;
		if(mov == 'E'){
			del.pb({1,0});
		}else if(mov == 'W'){
			del.pb({-1,0});
		}else if(mov == 'N'){
			del.pb({0,1});
		}else{
			del.pb({0,-1});
		}
		forn(j,v){
			int x,y; cin >> x >> y;
			cl[i].pb({x,y});
		}
	}
	
	vector<bool> rea(11000); //reached nodes
	
	int ans = 0; rea[pointTo({x0,y0})]=true;
	while(!rea[pointTo({xd,yd})]){
		update(rea);
		
		ans++;
	}
	
	
	return 0;
}
