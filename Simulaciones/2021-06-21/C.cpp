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
#define EPS 0.0000001 

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
	double norm(){return sqrt(x*x+y*y);}
	double norm_sq(){return x*x+y*y;}
};
double dist(pto a, pto b){return (b-a).norm();}

long double radius;
vector<ll> id,tam;
vector<pair<long double,long double>> arrx,arry;
vector<pto> ptos;
ll n;
long double x,y;

ll find(ll u){
	ll r=u;
	while(id[r]!=r) r=id[r];
	while(id[u]!=r){
		ll aux=id[u];
		id[u]=r;
		u=aux;
	}
	return r;
}

void unify(ll u,ll v){
	ll r1=find(u), r2=find(v);
	if(r1!=r2 && dist(ptos[u],ptos[v])<=2.0*radius){
		ll aux;
		if(tam[r1]>tam[r2]){
			aux=r2;
			r2=r1;
			r1=aux;
		}
		tam[r2]+=tam[r1];
		id[r1]=r2;
		arrx[r2].fst=min(arrx[r2].fst,arrx[r1].fst);
		arrx[r2].snd=max(arrx[r2].snd,arrx[r1].snd);
		arry[r2].fst=min(arry[r2].fst,arry[r1].fst);
		arry[r2].snd=max(arry[r2].snd,arry[r1].snd);
	}
	return;
}

void reset(){
	forn(i,n) id[i]=i;
	forn(i,n) tam[i]=1;
	
	forn(i,n){
		vector<pto> aptos(4);
		aptos[0]=pto(ptos[i].x,y);
		aptos[1]=pto(ptos[i].x,0.0);
		aptos[2]=pto(x,ptos[i].y);
		aptos[3]=pto(0.0,ptos[i].y);
		arrx[i].fst=ptos[i].x;
		arrx[i].snd=ptos[i].x;
		arry[i].fst=ptos[i].y;
		arry[i].snd=ptos[i].y;
		forn(j,4){
			if(dist(ptos[i],aptos[j])<=radius){
				long double aux = min(aptos[j].x,ptos[i].x);
				arrx[i].fst=min(aux,arrx[i].fst);
				aux = max(aptos[j].x,ptos[i].x);
				arrx[i].snd=max(aux,arrx[i].snd);
				aux=min(aptos[j].y,ptos[i].y);
				arry[i].fst=min(aux,arry[i].fst);
				aux=max(aptos[j].y,ptos[i].y);
				arry[i].snd=max(aux,arry[i].snd);
			}
		}
	}
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>x>>y;
	cin>>n;
	ptos.resize(n);
	id.resize(n);
	tam.resize(n);
	arrx.resize(n);
	arry.resize(n);
	
	forn(i,n) cin>>ptos[i].x>>ptos[i].y;
	long double l=0.0,r=max(x,y);
	pto s = pto(0.0,0.0);
	pto t = pto(x,y);
	
	forn(i,50){
		radius=(r+l)/2.0;
		reset();
		
		forn(j,n){
			forr(k,j+1,n){
				unify(j,k);
			}
		}
		
		bool ok=true;
		forn(j,n){
			if((arrx[j].fst==0.0 && arrx[j].snd==x) || (arry[j].fst==0.0 && arry[j].snd==y) 
			|| (arrx[j].fst==0.0 && arry[j].fst==0.0) || (arrx[j].snd==x && arry[j].snd==y)){ ok=false; break;}
			if(dist(s,ptos[j])<=radius || dist(t,ptos[j])<=radius){ok=false; break;}
		}
		
		if(ok){
			l=radius;
		}else{
			r=radius;
		}
	}
	cout<<fixed<<setprecision(7)<<radius<<"\n";
	
	return 0;
}




