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
typedef long double T;
const T EPS = 0.0000000001;

struct pto{
	T x,y;
	pto(T x=0, T y=0): x(x),y(y){}
	pto operator+(pto a){ return pto(x+a.x, y+a.y);}
	pto operator-(pto a){ return pto(x-a.x, y-a.y);}
	
	pto operator+(T a){ return pto(x+a, y+a);}
	pto operator*(T a){ return pto(x*a, y*a);}
	pto operator/(T a){ return pto(x/a, y/a);} 
	
	T operator*(pto a){ return x*a.x+y*a.y; }
	
	T operator^(pto a){ return x*a.y-y*a.x; }
	
	bool left(pto q, pto r){ return ((q-*this)^(r-*this))>0; }
	bool operator<(const pto &a) const{ return a<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
	bool operator == (pto a){ return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	T norm() { return sqrt(x*x+y*y); }
	T norm_sq() { return x*x + y*y; }
};

T dist(pto a, pto b) { return (b-a).norm(); }

struct line{
	T a,b,c;
	
	line(){}
	
	line(T a, T b, T c): a(a), b(b), c(c){}
	
	line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
};

T calc(pto p1, pto p2){
	return abs(p1^p2)/2.;
}

bool solve(pto p1, pto p2, pto p3, pto pe){
	T area = abs((p2-p1)^(p3-p1))/4.;
	pto v1 = (pe-p1);
	pto v2 = (p3-p1);
	
	T l = 0, r = 1;
	forn(i,100){
		T med = (l+r)/2.;
		
		if(calc(v1,v2*med)-area<0){
			l = med;
		}else{
			r = med;
		}
	}
	
	l = (l+r)/2.;
	if(abs(area-calc(v1,v2*l))<EPS){
		cout << fixed << setprecision(8) << v2.x*l+p1.x << " " << v2.y*l+p1.y << "\n";
		return true;
	}
	
	return false;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	forn(TT,t){
		int x, y;
		pto p1, p2, p3, pe;
		cin >> x >> y; p1 = pto(x,y);
		cin >> x >> y; p2 = pto(x,y);
		cin >> x >> y; p3 = pto(x,y);
		cin >> x >> y; pe = pto(x,y);
		
		bool ok = false;
		if(dist(p1,pe)+dist(pe,p2)<EPS+dist(p1,p2)){
			ok = solve(p1,p2,p3,pe);
			if(!ok) ok = solve(p2,p1,p3,pe);
		}else if(dist(p2,pe)+dist(pe,p3)<EPS+dist(p2,p3)){
			ok = solve(p2,p3,p1,pe);
			if(!ok) ok = solve(p3,p2,p1,pe);
		}else if(dist(p3,pe)+dist(pe,p1)<EPS+dist(p3,p1)){
			ok = solve(p3,p1,p2,pe);
			if(!ok) ok = solve(p1,p3,p2,pe);
		}else{
			cout << "-1\n";
		}
	}
	
	return 0;
}




