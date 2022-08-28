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
#define MAXN 100010

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef int tipo;


#define operacion(x, y) (x + y)
const tipo neutro=0;
struct RMQ {
	int sz;
	tipo t[4*MAXN];
	tipo &operator[](int p) {return t[sz+p];}
	void init(int n) {//O(nlgn)
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
	}
	void updall() {dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);} //O(n)
	tipo get(int i, int j) {return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b) {//O(lgn), [i, j)
		if(j<=a || i>=b) return neutro;
		if(i<=a && b<=j) return t[n];//n = node of range [a,b)
		int c = (a+b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	void set(int p, tipo val) {//O(lgn)
		p += sz;
		while(p>0 && t[p]!=val) {
			t[p] = val;
			p /= 2;
			val = operacion(t[p*2], t[p*2+1]);
		}
	}
};

RMQ as, bs, cs; int n;


int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	int t; cin >> t;
	forn(T,t){
		cin >> n;
		
		string x,y;
		cin >> x >> y;
		
		as.init(n); bs.init(n); cs.init(n);
		
		forn(i,n){
			if(x[i] == 'a'){
				as.set(i,1);
			}else if(x[i] == 'b'){
				bs.set(i,1);
			}else{
				cs.set(i,1);
			}
		}
		
		bool ok = true;
		forn(i,n){
			if(x[i] == y[i]) continue;
			if(x[i] == 'a' && y[i] == 'b'){
				
				int l = i, r = n-1;
				while(l<r){
					int med = (l+r)/2;
					
					int cantb = bs.get(i,med+1);
					if(cantb >= 1){
						r = med;
					}else{
						l = med+1;
					}
				}
				
				if(bs.get(i,l+1)==1 && cs.get(i,l+1)==0){
					x[i] = 'b', x[l] = 'a';
					bs.set(i,1); bs.set(l,0);
					as.set(i,0); as.set(l,1);
				}else{
					ok = false;
				}
				
			}else if(x[i] == 'b' && y[i] == 'c'){
				
				int l = i, r = n-1;
				while(l<r){
					int med = (l+r)/2;
					
					int cantc = cs.get(i,med+1);
					if(cantc >= 1){
						r = med;
					}else{
						l = med+1;
					}
				}
				
				if(cs.get(i,l+1)==1 && as.get(i,l+1)==0){
					x[i] = 'c', x[l] = 'b';
					cs.set(i,1); cs.set(l,0);
					bs.set(i,0); bs.set(l,1);
				}else{
					ok = false;
				}
				
			} else ok = false;
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




