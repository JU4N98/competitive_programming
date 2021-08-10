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
#define EPS 0.000000001

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
const double pi = acos(-1.0);

struct pto{
	double x, y;
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(double a){return pto(x+a, y+a);}
	pto operator*(double a){return pto(x*a, y*a);}
	pto operator/(double a){return pto(x/a, y/a);}
	//dot product, producto interno:
	double operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	double operator^(pto a){return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	double norm(){return sqrt(x*x+y*y);}
	double norm_sq(){return x*x+y*y;}
};

double angle(pto a, pto o, pto b){
	pto oa=a-o, ob=b-o;
	return atan2(oa^ob, oa*ob);
}

pto rotate(pto p, double theta){
	return pto(p.x*cos(theta)-p.y*sin(theta),
     p.x*sin(theta)+p.y*cos(theta));
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; double a, theta;
	cin>>n>>a;
	a *= (2*pi)/360.0;
	//~ cout<<a<<endl;
	theta = (2.0*pi) / double(n); 
	vector<pto> arr(n);
	arr[0] = pto(1.0,0.0);
	forr(i,1,n) arr[i] = rotate(arr[i-1],theta);
	//~ forn(i,n) cout<<arr[i].x<<" "<<arr[i].y<<endl;
	ii mini = {1,2};
	forr(i,1,n-1){
		int l=i+1,r=n-1;
		while(l+1<r){
			int med = (l+r)/2;
			//~ cout<<"0 "<<i<<" "<<med<<" :"<<angle(arr[0],arr[i],arr[med])*(-1.0)<<endl;
			if(-1.0*angle(arr[0],arr[i],arr[med])>=a){
				l = med;
			}else{
				r = med;
			}
		}
		if(abs(-1.0*angle(arr[0],arr[i],arr[l])-a)>abs(-1.0*angle(arr[0],arr[i],arr[r])-a)) l=r;
		//~ cout<<i<<" "<<l<<":"<<angle(arr[0],arr[i],arr[l])*(-1.0)<<endl;
		if(abs(-1.0*angle(arr[0],arr[mini.fst],arr[mini.snd])-a)>abs(-1.0*angle(arr[0],arr[i],arr[l])-a)) mini={i,l};
	}
	cout<<"1 "<<mini.fst+1<<" "<<mini.snd+1<<"\n";
	
	return 0;
}




