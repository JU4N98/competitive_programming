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
#define EPS 0.00000001
#define INF 1000000
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
	long double x,y;
	pto(long double x=0, long double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x,y+a.y);}
	pto operator-(pto a){return pto(x-a.x,y-a.y);}
	pto operator+(long double a){return pto(x+a,y+a);}
	pto operator*(long double a){return pto(x*a,y*a);}
	pto operator/(long double a){return pto(x/a,y/a);}
	long double operator*(pto a){return x*a.x+y*a.y;}
	long double operator^(pto a){return x*a.y-y*a.x;}
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
	bool operator==(pto a){return(x-a.x)<EPS && abs(y-a.y)<EPS;}
	long double norm(){return sqrt(x*x+y*y);}
	long double norm_sq(){return x*x+y*y;}
};
long double dist_sq(pto a, pto b){return (b-a).norm_sq();}
long double dist(pto a, pto b){return (b-a).norm();}
typedef pto vec;

int sgn(ll x){return x<0? -1 : !!x;}
struct line{
	line(){}
	long double a,b,c;
	line(long double a, long double b, long double c): a(a), b(b), c(c){}
	line(pto p, pto q): a(q.y-p.y),b(p.x-q.x),c(a*p.x+b*p.y){}
	int side(pto p){return sgn(ll(a)*p.x+ll(b)*p.y-c);}
};

pto inter(line l1,line l2){
	long double det=l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF, INF);
	return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
}

struct segm{
	pto s,f;
	segm(pto s, pto f): s(s), f(f) {}
	pto closest(pto p){
		long double l2=dist_sq(s,f);
		if(l2==0.) return s;
		long double t = ((p-s)*(f-s))/l2;
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
	
	
	int n,m;
	cin>>n;
	queue<pto> a,b;
	forn(i,n){
		long double x,y;
		cin>>x>>y;
		a.push(pto(x,y));
	}
	cin>>m;
	forn(i,m){
		long double x,y;
		cin>>x>>y;
		b.push(pto(x,y));
	}
	
	bool corte=false;
	pto pa1=a.front(),pb1=b.front();
	a.pop();b.pop();
	pto pa2=a.front(),pb2=b.front(),ori=pto(0.0,0.0),pb=pb1-pa1;
	a.pop();b.pop();
	long double ans=pb.norm();
	do{
		vec va=pa2-pa1,vb=pb2-pb1;
		va=va/(va.norm());
		vb=vb/(vb.norm());
		long double desp;
		if(EPS<dist(pb1,pb2)-dist(pa1,pa2)){
			desp=dist(pa1,pa2);
			pb1=pb1+(vb/vb.norm())*desp;
			pa1=pa2;
			if(!a.empty()){ pa2=a.front(); a.pop(); }else corte=true;
		}else if(dist(pa1,pa2)-dist(pb1,pb2)>EPS){
			desp=dist(pb1,pb2);
			pa1=pa1+(va/va.norm())*desp;
			pb1=pb2;
			if(!b.empty()){ pb2=b.front(); b.pop(); }else corte=true;
		}else{
			desp=dist(pb1,pb2);
			pa1=pa2;
			if(!a.empty()){ pa2=a.front(); a.pop(); }else corte=true;
			pb1=pb2;
			if(!b.empty()){ pb2=b.front(); b.pop(); }else corte=true;
		}
		va=va*desp;
		vb=vb*desp;
		vec d=(vb-va);
		segm s = segm(pb,pb+d);
		ans=min(ans,s.closest(ori).norm());
		pb=pb+d;
	}while(!corte);
	cout<<fixed<<setprecision(7)<<ans<<"\n";
	
	return 0;
}
