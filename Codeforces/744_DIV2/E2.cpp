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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef int tipo;

#define MAXN 200010
#define operacion(x, y) (x+y)
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

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin>>t;
	RMQ stree; stree.init(200005);
	forn(T,t){
		int n; cin>>n;
		vector<int> arr(n),arro(n),lwr(n),eq(n); forn(i,n) cin>>arr[i];
		arro=arr; sort(arro.begin(),arro.end());
		map<int,int> m; m[arro[0]]=0; forr(i,1,n) if(arro[i]!=arro[i-1]) m[arro[i]]=m[arro[i-1]]+1;
		forn(i,n) stree.set(i,0);
		forn(i,n){
			int idx = m[arr[i]];
			eq[i]=stree.get(idx,idx+1);
			stree.set(idx,eq[i]+1);
			lwr[i]=stree.get(0,idx);
		}
		ll ans=0LL;
		dforn(i,n){
			//cout<<lwr[i]<<" "<<i-lwr[i]<<endl;
			ans+=min(lwr[i],i-lwr[i]-eq[i]);
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}




