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
#define EPS 0.0000000001
//#define INF 1e18

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
const long double pi = acos(-1.0);
const int MOD = 1000000007;
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
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
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

//~ int sgn(ll x){return x<0? -1 : !!x;}
//~ struct line{
	//~ line() {}
	//~ double a,b,c;//Ax+By=C
//~ //pto MUST store float coordinates!
	//~ line(double a, double b, double c):a(a),b(b),c(c){}
	//~ // TO DO chequear porque paso problema metiendo negativo el C (-(todo el calculo como esta))
	//~ line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
	//~ int side(pto p){return sgn(ll(a) * p.x + ll(b) * p.y - c);}
//~ };

//~ bool parallels(line l1, line l2){return abs(l1.a*l2.b-l2.a*l1.b)<EPS;}
//~ pto inter(line l1, line l2){//intersection
	//~ double det=l1.a*l2.b-l2.a*l1.b;
	//~ if(abs(det)<EPS) return pto(INF, INF);//parallels
	//~ return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
//~ }

struct segm{
	pto s,f;
	segm(pto s, pto f):s(s), f(f) {}
	//~ pto closest(pto p) {//use for dist to point
	   //~ double l2 = dist_sq(s, f);
	   //~ if(l2==0.) return s;
	   //~ double t =((p-s)*(f-s))/l2;
	   //~ if (t<0.) return s;//not write if is a line
	   //~ else if(t>1.)return f;//not write if is a line
	   //~ return s+((f-s)*t);
	//~ }
    bool inside(pto p){return abs(dist(s, p)+dist(p, f)-dist(s, f))<EPS;}
};

pair<int,int> pend(pto p1, pto p2){
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
	cin>>h.x>>h.y;
	cin>>g.xi>>g.yi;
	g.x = double(g.xi); g.y =double(g.yi);
	int n;
	cin>>n;
	vector<pto> arr(n);
	forn(i,n){
		cin>>arr[i].xi>>arr[i].yi;
		arr[i].x=double(arr[i].xi),arr[i].y=double(arr[i].yi);
	}
	set<pair<long double,int>> angles;
	map<pto,int> dp;
	map<pto,map<pair<int,int>,int>> direc;
	
	forn(i,n){
		if(angle(g,h,arr[i])<0.0) angles.insert({2.0*pi-(angle(g,h,arr[i])+2.0*pi),i});
		else angles.insert({2.0*pi-angle(g,h,arr[i]),i});
	}
	arr.pb(g);
	angles.insert({2.0*pi,n});
	
	//~ forall(it,angles) cout<<it->snd<<" ";
	//~ cout<<endl;
	//~ forall(it,angles) cout<<it->fst<<" ";
	//~ cout<<endl;
	
	auto fin = angles.lower_bound({pi-EPS,0});
	//~ cout<<fin->fst<<" "<<fin->snd<<endl;
	for(auto it = angles.begin(); it!=fin;it++){
		pto p = arr[it->snd];
		dp[p] = 1;
		direc[p][pend(g,p)] = 1;
		//~ cout<<it->snd<<" "<<pend(g,p)<<endl;
	}
	
	//~ forall(it,angles) cout<<dp[arr[it->snd]]<<" ";
	//~ cout<<endl;
	
	forall(it,angles){
		long double a = it->fst;
		pto p = arr[it->snd];
		
		//~ cout<<"pto "<<it->snd<<"\n";
		//~ cout<<dp[p]<<endl;
		
		fin = angles.lower_bound({a+pi-EPS,0});
		//~ cout<<"	"<<fin->snd<<endl;
		for(auto it2 = angles.lower_bound({a,n+1}); it2!=fin;it2++){
			
			pto p2 = arr[it2->snd];
			bool ok = true;
			segm s(p,p2);
			for(auto it3 = angles.begin(); it3!=angles.end(); it3++){
				if(it3!=it2 && it3!=it && s.inside(arr[it3->snd])) ok=false;
			}
			if(!ok) continue;
			dp[p2] = sum(sum(dp[p2],dp[p]),- direc[p][pend(p,p2)]);
			//~ cout<<"	"<<it2->snd<<" direc["<<pend(p,p2).fst<<","<<pend(p,p2).snd<<"]="<< direc[p][pend(p,p2)]<<endl;
			direc[p2][pend(p,p2)] = sum(direc[p2][pend(p,p2)],sum(dp[p],- direc[p][pend(p,p2)]));
		}
		//~ forall(it2,angles) cout<<dp[arr[it2->snd]]<<" ";
		//~ cout<<endl;
	}
	
	cout<<(dp[g]%MOD+MOD)%MOD<<"\n";
	
	
	return 0;
}




