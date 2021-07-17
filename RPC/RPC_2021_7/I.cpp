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
//#define ANARAP
#define INF 1e18
#define MAX_V 300000
#define EPS 1e-9
int N;

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct pto{
	double x, y;
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(double a){return pto(x+a, y+a);}
	pto operator*(double a){return pto(x*a, y*a);}
	pto operator/(double a){return pto(x/a, y/a);}
	double operator*(pto a){return x*a.x+y*a.y;}
	double operator^(pto a){return x*a.y-y*a.x;}
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
bool operator!=(pto a){return !(abs(x-a.x)<EPS && abs(y-a.y)<EPS);}
	double norm(){return sqrt(x*x+y*y);}
	double norm_sq(){return x*x+y*y;}
};
double dist(pto a, pto b){return (b-a).norm();}
double dist_sq(pto a, pto b){return (b-a).norm_sq();}

int sgn(ll x){return x<0? -1 : !!x;}
struct line{
	line() {}
	double a,b,c;
	line(double a, double b, double c):a(a),b(b),c(c){}
	line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
	int side(pto p){return sgn(ll(a) * p.x + ll(b) * p.y - c);}
};
bool parallels(line l1, line l2){return abs(l1.a*l2.b-l2.a*l1.b)<EPS;}

pto inter(line l1, line l2){
	double det=l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF, INF);
	return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
}

struct segm{
	pto s,f,in;
	segm(pto s, pto f):s(s), f(f) {}
	pto closest(pto p) {
	   double l2 = dist_sq(s, f);
	   if(l2==0.) return s;
	   double t =((p-s)*(f-s))/l2;
	   if (t<0.) return s;
	   else if(t>1.)return f;
	   return s+((f-s)*t);
	}
    bool inside(pto p){return abs(dist(s, p)+dist(p, f)-dist(s, f))<EPS;}
};

//NOTA: Si los segmentos son coolineales solo devuelve un punto de interseccion
pto inter(segm s1, segm s2){
    if(s1.inside(s2.s)) return s2.s;
    if(s1.inside(s2.f)) return s2.f;
	pto r=inter(line(s1.s, s1.f), line(s2.s, s2.f));
    if(s1.inside(r) && s2.inside(r)) return r;
	return pto(INF, INF);
}

vector<pair<long double,int>> G[MAX_V];
#define add(a, b, w) G[a].pb(make_pair(w, b))
vector<long double> dijkstra(int s){
	priority_queue<pair<long double,int>, vector<pair<long double,int>>, greater<pair<long double,int>> > Q;
	vector<long double> dist(N, INF); vector<int> dad(N, -1);
	Q.push(make_pair(0, s)); dist[s] = 0;
	while(sz(Q)){
		pair<long double,int> p = Q.top(); Q.pop();
		forall(it, G[p.snd]){
			if(dist[p.snd]+it->first < dist[it->snd]){
				dist[it->snd] = dist[p.snd] + it->fst;
				dad[it->snd] = p.snd;
				Q.push(make_pair(dist[it->snd], it->snd));	
			}
		}
	}
	return dist;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<segm> vs;
	vector<line> vl;
	
	forn(i,n){
		long double x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		vs.pb(segm(pto(x1,y1),pto(x2,y2)));
		vl.pb(line(pto(x1,y1),pto(x2,y2)));
	}
	pto si,fi,ff;
	long double vels,velf;
	cin>>si.x>>si.y>>vels;
	cin>>fi.x>>fi.y>>ff.x>>ff.y>>velf;
	
	int cant=0;
	map<pto,int> mint;
	map<int,pto> intm;
	
	segm sf = segm(fi,ff);
	line lf = line(fi,ff);
	vector<pto> interf;
	forn(i,sz(vs)){
		if(parallels(lf,vl[i])) continue;
		vs[i].in=inter(vs[i],sf);
		if(inter(vs[i],sf)!=pto(INF,INF)) interf.pb(inter(vs[i],sf));
	}
	
	forn(i,sz(vs)){
		vector<pair<long double,pto>> vdp;
		
		vdp.pb({0.0,vs[i].s});
		if(vs[i].in!=pto(INF,INF)) vdp.pb({dist(vs[i].in,vs[i].s),vs[i].in});
		vdp.pb({dist(vs[i].s,vs[i].f),vs[i].f});
		
		forn(j,sz(vs)){
			pto p = inter(vs[i],vs[j]);
			if(p!=pto(INF,INF)) vdp.pb({dist(p,vs[i].s)/vels,p});
		}
		
		sort(vdp.begin(),vdp.end());
		
		forn(j,sz(vdp)-1){
			if(mint.find(vdp[j].snd)==mint.end()){ mint[vdp[j].snd]=cant; intm[cant]=vdp[j].snd; cant++;}
			if(mint.find(vdp[j+1].snd)==mint.end()){ mint[vdp[j+1].snd]=cant; intm[cant]=vdp[j+1].snd; cant++;}
			
			add(mint[vdp[j].snd],mint[vdp[j+1].snd],dist(vdp[j].snd,vdp[j+1].snd));
			add(mint[vdp[j+1].snd],mint[vdp[j].snd],dist(vdp[j].snd,vdp[j+1].snd));
		}
	}
	
	N=cant+5;
	vector<long double> distance = dijkstra(mint[si]);
	
	long double mindist = INF;
	forn(i,sz(interf)){
		if(distance[mint[interf[i]]] - dist(interf[i],fi)/velf <= EPS) mindist=min(mindist,dist(interf[i],fi)/velf);
	}
	
	if(mindist==INF) cout<<"Impossible\n";
	else cout<<fixed<<setprecision(10)<<mindist<<"\n";
	
	return 0;
}




