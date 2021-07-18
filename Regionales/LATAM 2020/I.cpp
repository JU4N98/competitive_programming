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
#define EPS 0.00000000001
//#define INF 1e18

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
const long double pi = acos(-1.0);
const ll MOD = 1000000007;
#define sum(x,y) ((x+y)%MOD+MOD)%MOD

struct pto{
	long double x, y;
	int xi,yi;
	pto(long double x=0, long double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(long double a){return pto(x+a, y+a);}
	pto operator*(long double a){return pto(x*a, y*a);}
	pto operator/(long double a){return pto(x/a, y/a);}
	//dot product, producto interno:
	long double operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	long double operator^(pto a){return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>=0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	long double norm(){return sqrt(x*x+y*y);}
	long double norm_sq(){return x*x+y*y;}
};
long double dist(pto a, pto b){return (b-a).norm();}
typedef pto vec;

long double angle(pto a, pto o, pto b){
	pto oa=a-o, ob=b-o;
	return atan2(oa^ob, oa*ob);
}

struct segm{
	pto s,f;
	segm(pto s, pto f):s(s), f(f) {}
    bool inside(pto p){return abs(dist(s, p)+dist(p, f)-dist(s, f))<EPS;}
};

ii norma(pto p1, pto p2){
	int gcd = __gcd(p2.xi-p1.xi,p2.yi-p1.yi);
	return {(p2.xi-p1.xi)/gcd,(p2.yi-p1.yi)/gcd};
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	pto h,g;
	cin>>h.xi>>h.yi; h.x=double(h.xi),h.y=double(h.yi);
	cin>>g.xi>>g.yi; g.x=double(g.xi),g.y=double(g.yi);
	ll n;
	cin>>n;
	vector<pair<long double,pto>> ptos(n);
	vector<vector<int>> G(n+1);
	forn(i,n){ cin>>ptos[i].snd.xi>>ptos[i].snd.yi; ptos[i].snd.x=double(ptos[i].snd.xi); ptos[i].snd.y=double(ptos[i].snd.yi); }
	
	forn(i,n){
		if(angle(g,h,ptos[i].snd)<0.0) ptos[i].fst=-angle(g,h,ptos[i].snd);
		else ptos[i].fst=2.0*pi-angle(g,h,ptos[i].snd);
	}
	ptos.pb({2.0*pi,g});
	sort(ptos.begin(),ptos.end());
	
	vector<vector<ll>> dp(n+1);
	forn(i,n+1) dp[i].resize(n+1,0);
	
	forn(i,n+1){
		long double a1 = ptos[i].fst;
		forr(j,i+1,n+1){
			long double a2 = ptos[j].fst;
			if(a2>a1+EPS && a2<a1+pi-EPS){
				G[i].pb(j);
			}
		}
	}
	
	forn(i,n+1) if(ptos[i].fst<pi-EPS) dp[i][n]=1;
	
	forn(i,n+1){
		forn(j,n+1){
			forn(k,sz(G[i])){
				int v = G[i][k];
				if(!ptos[v].snd.left(ptos[j].snd,ptos[i].snd)){
					dp[v][i] = sum(dp[v][i],dp[i][j]);
				}
			}
		}
	}
	
	ll ans=0;
	forn(i,n+1) ans=sum(ans,dp[n][i]);
	cout<<sum(ans,0)<<"\n";
	
	return 0;
}




