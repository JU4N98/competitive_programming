#include <bits/stdc++.h>
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
#define MAXN 200010
#define operacion(x, y) max(x, y)
#define operacion2(x, y) min(x, y)

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef long long tipo;


const tipo neutro2=1000000;
const tipo neutro=-1000000;

struct RMQmax {
	int sz;
	tipo t[4*MAXN];
	tipo &operator[](int p) {return t[sz+p];}
	void init(int n) {
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
	}
	void updall() {dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);}
	tipo get(int i, int j) {return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b) {
		if(j<=a || i>=b) return neutro;
		if(i<=a && b<=j) return t[n];
		int c = (a+b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	void set(int p, tipo val) {
		p += sz;
		while(p>0 && t[p]!=val) {
			t[p] = val;
			p /= 2;
			val = operacion(t[p*2], t[p*2+1]);
		}
	}
};

struct RMQmin {
	int sz;
	tipo t[4*MAXN];
	tipo &operator[](int p) {return t[sz+p];}
	void init(int n) {
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro2;
	}
	void updall() {dforn(i, sz) t[i]=operacion2(t[2*i], t[2*i+1]);}
	tipo get(int i, int j) {return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b) {
		if(j<=a || i>=b) return neutro2;
		if(i<=a && b<=j) return t[n];
		int c = (a+b)/2;
		return operacion2(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	void set(int p, tipo val) {
		p += sz;
		while(p>0 && t[p]!=val) {
			t[p] = val;
			p /= 2;
			val = operacion2(t[p*2], t[p*2+1]);
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
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,m;
		cin>>n>>m;
		vector<ll> arr(n+1);
		RMQmin mini;
		mini.init(n+1);
		RMQmax maxi;
		maxi.init(n+1);
		ll x=0;
		arr[0]=x;
		mini.set(0,x);
		maxi.set(0,x);
		string ope;
		cin>>ope;
		forr(i,1,n+1){
			if(ope[i-1]=='+'){
				x++;
			}else{
				x--;
			}
			arr[i]=x;
			mini.set(i,arr[i]);
			maxi.set(i,arr[i]);
		}
		
		forn(i,m){
			ll l,r;
			cin>>l>>r;
			if(l==0 && r==n){
				cout<<"1\n";
			}else if(l==0){
				//cout<<"CASO 1\n";
				ll minim=mini.get(r+1,n+1), maxim=maxi.get(r+1,n+1);
				//cout<<maxim<<" "<<minim<<endl;
				cout<<maxim-minim+1<<"\n";
			}else if(r==n){
				//cout<<"CASO 2\n";
				ll minim=mini.get(0,l), maxim=maxi.get(0,l);
				//cout<<maxim<<" "<<minim<<endl;
				cout<<maxim-minim+1<<"\n";
			}else{
				//cout<<"CASO 3\n";
				ll minim=mini.get(0,l), maxim=maxi.get(0,l);
				ll minim2=mini.get(r+1,n+1)-arr[r]+arr[l-1], maxim2=maxi.get(r+1,n+1)-arr[r]+arr[l-1];
				//cout<<maxim<<" "<<minim<<endl;
				//cout<<maxim2<<" "<<minim2<<endl;
				cout<<max(maxim,maxim2)-min(minim,minim2)+1<<"\n";
			}
		}
	}
	
	
	return 0;
}

