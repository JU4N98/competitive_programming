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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef ll tipo;

const ll MAXN = 101000;
const tipo neutro = 0;
#define operacion(x,y) x+y

struct RMQ{
	int sz;
	tipo t[4*MAXN];
	tipo & operator[](int p){return t[sz+p];}
	void init(int n){
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
	}
	
	void updall() {dforn(i,sz) t[i] = operacion(t[2*i], t[2*i+1]);}
	tipo get(int i, int j) {return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b){
		if(j<=a || i>=b) return neutro;
		if(i<=a && b<=j) return t[n];
		int c = (a+b)/2;
		return operacion(get(i,j,2*n,a,c),
		get(i,j,2*n+1,c,b));
	}
	void set(int p, tipo val){
		p += sz;
		while(p>0 && t[p] != val){
			t[p] = val;
			p /= 2;
			val = operacion(t[p*2],t[p*2+1]);
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
	
	
	int t; cin >> t;
	RMQ st; 
	forn(T,t){
		int n; cin >> n;
		vector<int> num(n), num2; forn(i,n) cin >> num[i];
		
		vector<ll> ans;
		
		
		ll sum = 0; ans.pb(sum);
		st.init(n+3);
		int maxi = 0, cnt = 1;
		st.set(num[0],1);
		forr(i,1,n){
			if(num[maxi] < num[i]){
				sum += cnt+1;
				maxi = i;
				cnt = 1;
			}else if(num[i] == num[maxi]){
				cnt++;
			}else{
				sum += st.get(num[i]+1,num[maxi]+1);
			}
			st.set(num[i],1);
			ans.pb(sum);
		}
		
		forn(i,n){
			cout << ans[i];
			if(i!=n-1) cout << " "; else cout << "\n";
		}
	}
	
	return 0;
}




