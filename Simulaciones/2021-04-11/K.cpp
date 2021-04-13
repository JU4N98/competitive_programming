#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
#define EPS 1
//#define ANARAP
#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct pto{
	double x,y;
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x,y+a.y);}
	pto operator-(pto a){return pto(x-a.x,y-a.y);}
	pto operator+(double a){return pto(x+a,y+a);}
	pto operator*(double a){return pto(x*a,y*a);}
	pto operator/(double a){return pto(x/a,y/a);}
	double operator*(pto a){return x*a.x+y*a.y;}
	double operator^(pto a){return x*a.y-y*a.x;}
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
	bool operator==(pto a){return(x-a.x)<EPS && abs(y-a.y)<EPS;}
	double norm(){return sqrt(x*x+y*y);}
	double norm_sq(){return x*x+y*y;}
};

double dist(pto a, pto b){return (b-a).norm();}
typedef pto vec;

int sgn(ll x){return x<0? -1 : !!x;}
struct line{
	line(){}
	double a,b,c;
	line(double a, double b, double c): a(a), b(b), c(c){}
	line(pto p, pto q): a(q.y-p.y),b(p.x-q.x),c(a*p.x+b*p.y){}
	int side(pto p){return sgn(ll(a)*p.x+ll(b)*p.y-c);}
};

pto inter(line l1,line l2){
	double det=l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF, INF);
	return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
}

struct segm{
	pto s,f;
	segm(pto s, pto f): s(s), f(f) {}
	pto closest(pto p){
		double l2=dist_sq(s,f);
		if(l2==0.) return s;
		double t = ((p-s)*(f-s))/l2;
		if(t<0.) return s;
		else if(t>1.) return f;
		return s+((f-s)*t);
	}
	bool inside(pto p){return abs(dist(s,p)+dist(p,f)-dist(s,f))<EPS;}
};


int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	return 0;
}
