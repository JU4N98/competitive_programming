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

struct pto{
	ll x,y;
	pto(ll x = 0, ll y = 0): x(x),y(y){}
	pto operator+(pto a) { return pto(x+a.x,y+a.y); }
	pto operator-(pto a) { return pto(x-a.x,y-a.y); }
	pto operator+(ll a) { return pto(x+a, y+a); }
	pto operator*(ll a) { return pto(x*a, y*a); }
	
	bool operator<(const pto &a) const{return x<a.x || (x-a.x == 0 && y<a.y);}
};

pto calcNext(pto p, pto dir, ll n, ll m){
	ll fact = 0;
	if(dir.x == 1){
		if(dir.y == 1){
			fact = min(n-p.x,m-p.y);
		}else{
			fact = min(n-p.x,p.y);
		}
	}else{
		if(dir.y == 1){
			fact = min(p.x,m-p.y);
		}else{
			fact = min(p.x,p.y);
		}
	}
	return p + dir*fact;
}

ll calcAns(set<pair<pto,pto>> &lines, map<pair<pto,pto>,ll> &ti, pto p, ll n, ll m){
	ll ans = -1;
	
	pto p1 = calcNext(p,{-1,-1},n,m), p2 = calcNext(p,{1,1},n,m);
	
	if(lines.find({p1,p2}) != lines.end()){
		if(ans == -1LL) ans = ti[{p1,p2}] + abs(p.x-p1.x); 
		else ans = min(ans,ti[{p1,p2}] + abs(p.x-p1.x));
	}
	
	if(lines.find({p2,p1}) != lines.end()){
		if(ans == -1LL) ans = ti[{p2,p1}] + abs(p.x-p2.x);
		else ans = min(ans,ti[{p2,p1}] + abs(p.x-p2.x));
	}
	
	p1 = calcNext(p,{-1,1},n,m), p2 = calcNext(p,{1,-1},n,m);
	
	if(lines.find({p1,p2}) != lines.end()){
		if(ans == -1LL) ans = ti[{p1,p2}] + abs(p.x-p1.x);
		else ans = min(ans,ti[{p1,p2}] + abs(p.x-p1.x));
	}
	
	if(lines.find({p2,p1}) != lines.end()){
		if(ans == -1LL) ans = ti[{p2,p1}] + abs(p.x-p2.x);
		else ans = min(ans,ti[{p2,p1}] + abs(p.x-p2.x));
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
	
	ll n, m; int k; cin >> n >> m >> k;
	vector<pto> ptos(k); forn(i,k) cin >> ptos[i].x >> ptos[i].y;
	
	set<pto> visi;
	set<pair<pto,pto>> lines;
	map<pair<pto,pto>,ll> ti;
	
	ll t = 0;
	pto cur = {0,0}; 
	pto dir = {1,1};
	vector<pto> corner(4);
	corner[0] = {0,0}; 
	corner[1] = {n,0}; 
	corner[2] = {0,m}; 
	corner[3] = {n,m};
	
	while(visi.find(cur) == visi.end()){
		visi.insert(cur);
		
		pto nxt = calcNext(cur,dir,n,m);
		
		lines.insert({cur,nxt});
		ti[{cur,nxt}] = t;
		
		t += abs(nxt.x-cur.x);
		
		cur = nxt;
		bool isCorner = false;
		forn(i,4) isCorner |= cur.x == corner[i].x && cur.y == corner[i].y;
		if(isCorner) break;
		
		if(cur.x == 0 || cur.x == n) dir.x *= -1;
		else dir.y *= -1;
	}
	
	
	forn(i,k) cout << calcAns(lines, ti, ptos[i], n, m) << "\n";
	
	
	return 0;
}
