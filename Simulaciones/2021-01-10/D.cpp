#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP
#ifdef ANARAP
#else
#endif

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
double EPS = 1e-15, INF=2e30;
struct pto{
	double x,y;
	bool inf;
	pto(double x=0, double y=0): x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x,y+a.y);}
	pto operator-(pto a){return pto(x-a.x,y-a.y);}
	pto operator+(double a){return pto(x+a,y+a);}
	pto operator*(double a){return pto(x*a,y*a);}
	pto operator/(double a){return pto(x/a,y/a);}
	double operator*(pto a){return x*a.x+y*a.y;}
	double operator^(pto a){return x*a.y-y*a.x;}
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
	bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	double norm() {return sqrt(x*x+y*y);}
	double norm_sqrt(){return x*x+y*y;}
};

double dist(pto a, pto b){return (b-a).norm();}
typedef pto vec;

struct line{
	line(){}
	double a,b,c;
	line(double a, double b, double c): a(a), b(b), c(c){}
	line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y){}
};

pto inter(line l1, line l2){
	double det=l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF,INF);
	return pto(l2.b*l1.c-l1.b*l2.c,l1.a*l2.c-l2.a*l1.c)/det;
}

line bisector(pto x, pto y){
	line l=line(x,y); pto m=(x+y)/2;
	return line(-l.b,l.a,-l.b*m.x+l.a*m.y);
}

struct Circle{
	pto o;
	double r;
	Circle(pto x, pto y, pto z){
		o=inter(bisector(x,y),bisector(y,z));
		r=dist(o,x);
	}
	Circle(){}
};

int main(){
	#ifdef ANARAP
	freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin>>n;
	vector<pto> trees(n);
	forn(i,n){
		double x,y;
		char info;
		cin>>x>>y>>info;
		pto p = pto(x,y);
		p.inf=info=='I';
		trees[i]=p;
	}
	
	bool sol=false;
	
	if(n<=2){
		cout<<"No\n";
		return 0;	
	}
	
	forn(i,n){
		forr(j,i+1,n){
			forr(k,j+1,n){
				Circle circ = Circle(trees[i],trees[j],trees[k]);
				if(circ.o.x!=INF){
					sol=true;
					forn(l,n){
						if(l!=i && l!=j && l!=k){
							if(trees[l].inf && dist(circ.o,trees[l])>circ.r){ sol=false; break;}
							else if(!trees[l].inf && dist(circ.o,trees[l])<circ.r){ sol=false; break;}
						}
					}
					//cout<<i<<" "<<j<<" "<<k<<endl; 
					//cout<<circ.o.x<<" "<<circ.o.y<<" "<<circ.r<<endl; 
					if(sol) break;
				}
			}
			if(sol) break;
		}
		if(sol) break;
	}
	if(sol) cout<<"No\n";
	else{
		forn(i,n){
			forr(j,i+1,n){
				pto o = pto((trees[i].x+trees[j].x)/2,(trees[i].y+trees[j].y)/2);
				Circle circ;
				circ.o=o;
				circ.r=dist(trees[i],trees[j])/2;
				sol=true;
				forn(l,n){
					if(l!=i && l!=j){
							if(trees[l].inf && dist(circ.o,trees[l])>circ.r){ sol=false; break;}
							else if(!trees[l].inf && dist(circ.o,trees[l])<circ.r){ sol=false; break;}
					}
					//cout<<i<<" "<<j<<endl; 
				}
				if(sol) break;
			}
			if(sol) break;
		}
		if(sol) cout<<"No\n";
		else cout<<"Yes\n";
	}
	
	return 0;
}


