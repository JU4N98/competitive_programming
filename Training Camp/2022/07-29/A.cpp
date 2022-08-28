
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
#define sqr(a) ((a)*(a))
#define feq(a,b) (fabs((a)-(b))<EPS)

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef double T;
const T EPS = 0.0000000001;

struct pto{
	T x,y;
	pto(T x=0, T y=0): x(x),y(y){}
	pto operator+(pto a){ return pto(x+a.x, y+a.y);}
	pto operator-(pto a){ return pto(x-a.x, y-a.y);}
	pto operator+(T a){ return pto(x+a,y+a);}
	pto operator*(T a){ return pto(x*a,y*a);}
	pto operator/(T a){ return pto(x/a,y/a);}
	
	T operator*(pto a){ return x*a.x+y*a.y; }
	T operator^(pto a){ return x*a.y-y*a.x; }
	
	
	bool operator<(const pto &a) const{ return x<a.x-EPS || (abs(x-a.x) && y<a.y-EPS);}
	bool operator==(pto a){ return abs(x-a.x)<EPS && abs(y-a.y)<EPS; }
	T norm(){ return sqrt(x*x+y*y);}
	T norm_sq(){ return x*x+y*y;}
	
}; 

T dist(pto a, pto b){ return (b-a).norm();}
T dist_sq(pto a, pto b){ return (b-a).norm_sq();}

line bisector(pto x, pto y){
	line l = line(x,y); pto m = (x+y)/2;
	return line(-l.b, l.a, -l.b * m.x + l.a * m.y);
}

struct circle{
	pto o;
	T r;
	
	circle(pto x, pto y, pto z){
		o = inter(bisector(x,y),bisector(y,z));
		r = dist(o,x);
	}
};

pair<pto,pto> ecCuad(T a, T b, T c){
	T dx = sqrt(b*b-4.*a*c);
	return make_pair((-b + dx) / (2.*a), (-b -dx)/(2.*a));
}

pair<pto,pto> interCL(circle c, line l){
	bool sw = false;
	if((sw = feq(0,l.b))){
		swap(l.a, l.b);
		swap(c.o.x, x.o.y);
	}
	pair<T,T> rc = ecCuad(
		sqr(l.a) + sqr(l.b),
	);
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	return 0;
}





