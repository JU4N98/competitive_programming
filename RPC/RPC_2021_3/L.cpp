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
#define MAXN (1<<20)
#define MAXN2 (1<<19)
#define operacion(x,y) x+y
#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef ll tf;
typedef vector<tf> poly;

typedef ll tipo;
//const tf MOD=230584300955636993,RT=5;
const tipo neutro=0;

struct CD{
	double r,i;
	CD(double r=0,double i=0): r(r),i(i){}
	double real() const {return r;}
	void operator/=(const int c){r/=c,i/=c;}
};
CD operator *(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
}
CD operator+(const CD& a, const CD& b){
	return CD(a.r+b.r,a.i+b.i);
}
CD operator-(const CD& a, const CD& b){
	return CD(a.r-b.r,a.i-b.i);
}
const double pi =  acos(-1.0);

CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	forr(i,0,n) if(R[i]<i) swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv? -1: 1);
		CD wi=CD(cos(z),sin(z));
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k]; CD v=a[k2]*w; a[k]=u+v; a[k2]=u-v; w=w*wi;
			}
		}
	}
	if(inv) forr(i,0,n) a[i]/=n;
}

poly multiply(poly& p1, poly& p2, bool special){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	forr(i,0,m){R[i]=0;forr(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	forr(i,0,m){
		cp1[i]=0,cp2[i]=0;
	}
	if(special)
	{
		forr(i,0,p1.size()) if(p1[i] != -1) cp1[i].r = cos(2*pi*p1[i]/28.0), cp1[i].i = sin(2*pi*p1[i]/28.0); 
		forr(i,0,p2.size()) if(p2[i] != -1) cp2[i].r = cos(2*pi*p2[i]/28.0), cp2[i].i = -sin(2*pi*p2[i]/28.0); 
	}
	else
	{
		forr(i,0,p1.size())cp1[i]=p1[i];
		forr(i,0,p2.size())cp2[i]=p2[i];
	}
	dft(cp1,m,false);dft(cp2,m,false);
	forr(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	n-=2;
	poly res;
	forr(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5));
	return res;
}

struct RMQ{
	int sz;
	tipo t[4*MAXN2];
	tipo &operator[](int p){return t[sz+p];}
	void init(int n){
		sz = 1 <<(32 - __builtin_clz(n));
		forn(i,2*sz) t[i]=neutro;
	}
	void updall() {dforn(i,sz) t[i]=operacion(t[2*i],t[2*i+1]);}
	tipo get(int i, int j){return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b){
		if(j<=a || i>=b) return neutro;
		if(i<=a && b<=j) return t[n];
		int c = (a+b)/2;
		return operacion(get(i,j,2*n,a,c),get(i,j,2*n+1,c,b));
	}
	void set(int p, tipo val){
		p+=sz;
		while(p>0 && t[p]!=val){
			t[p]=val;
			p/=2;
			val=operacion(t[p*2],t[p*2+1]);
		}
	}
};


int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m;
	cin>>n>>m;
	vector<ll> mapag, mapac;
	forn(i,n){
		char ins;
		int mov;
		cin>>ins;
		if(ins!='?') cin>>mov;
		switch(ins){
			case 'n':
				mapag.pb(mov-1);
			break;
			case 's':
				mapag.pb(7+mov-1);
			break;
			case 'e':
				mapag.pb(14+mov-1);
			break;
			case 'w':
				mapag.pb(21+mov-1);
			break;
			case '?':
				mapag.pb(-1);
			break;
		}
	}
	
	forn(i,m){
		char ins;
		int mov;
		cin>>ins;
		if(ins!='?') cin>>mov;
		switch(ins){
			case 'n':
				mapac.pb(mov-1);
			break;
			case 's':
				mapac.pb(7+mov-1);
			break;
			case 'e':
				mapac.pb(14+mov-1);
			break;
			case 'w':
				mapac.pb(21+mov-1);
			break;
			case '?':
				mapac.pb(-1);
			break;
		}
	}
	
	//cout<<"mapa grande: ";
	//forn(i,mapag.size()) cout<<mapag[i]<<" ";
	//cout<<endl;
	//cout<<"mapa chico: ";
	//forn(i,mapac.size()) cout<<mapac[i]<<" ";
	//cout<<endl;

	poly mapag_preg, mapac_preg;
	forn(i,n) if(mapag[i]==-1) mapag_preg.pb(1); else mapag_preg.pb(0);
	forn(i,m) if(mapac[i]==-1) mapac_preg.pb(1); else mapac_preg.pb(0);
	reverse(mapac_preg.begin(),mapac_preg.end());
	poly preg = multiply(mapag_preg,mapac_preg,false);
	
	//cout<<"preg: ";
	//forn(i,preg.size()) cout<<preg[i]<<" ";
	//cout<<endl;
	
	reverse(mapac.begin(),mapac.end());
	poly normal = multiply(mapag,mapac,true);
	reverse(mapac.begin(),mapac.end());
	
	//cout<<"normal: ";
	//forn(i,normal.size()) cout<<normal[i]<<" ";
	//cout<<endl;
	
	RMQ stree;
	stree.init(n);
	forn(i,n) if(mapag[i]==-1) stree.set(i,1); else stree.set(i,0);
	ll pregc=0;
	forn(i,m) if(mapac[i]==-1) pregc++; 
	
	//cout<<"pregc: "<<pregc<<endl;
	
	ll ans=0;
	//cout<<mapag.size()-mapac.size()<<endl;
	forr(i,mapac.size()-1,mapag.size()){
		cout<<"i: "<<i<<" normal: "<<normal[i]<<" stree["<<i-mapac.size()+1<<","<<i+1<<"]: "<<stree.get(i-(mapac.size()-1),i)<<" preg[i]: "<<preg[i]<<endl;
		if(normal[i]+stree.get(i-(mapac.size()-1),i+1)-preg[i]+pregc==mapac.size()) ans++;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}




