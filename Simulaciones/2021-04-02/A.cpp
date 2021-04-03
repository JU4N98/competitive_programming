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
#define ANARAP

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct pto{
	double x,y;
	pto(double x=0, double y=0): x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x,y+a.y);}
	pto operator-(pto a){return pto(x-a.x,y-a.y);}
	pto operator+(double a){return pto(x+a,y+a);}
	pto operator*(double a){return pto(x*a,y*a);}
	pto operator/(double a){return pto(x/a,y/a);}
	double operator*(pto a){return x*a.x+y*a.y;}
	double operator^(pto a){return x*a.y-y*a.x;}
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const {return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
	bool operator == (pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	double norm() {return sqrt(x*x,y*y);}
	double norm_sq(){return x*x+y*y;}
};

double

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




