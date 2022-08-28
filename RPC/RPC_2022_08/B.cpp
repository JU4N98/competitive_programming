#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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
#define x first
#define y second

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef __int128 ll;
typedef pair<ll,ll> ii;

struct frac{
	ll p, q;
	
	frac(ll P = 0, ll Q = 1) {
		p = P; q = Q;
		if(p == 0) q = 1;
		if(q<0) q = -q, p = -p;
	}
	
	void norm(){
		ll a = __gcd(q,p);
		if(a) p /= a, q /= a;
		else q = 1;
		if(q<0) q = -q, p = -p;
	}
	
	frac operator + (const frac & o){
		return frac(p*o.q+o.p*q,q*o.q);
	}
	
	frac operator - (const frac& o){
		return frac(p*o.q-o.p*q,q*o.q);
	}
	
	frac operator * (frac o){
		return frac(p*o.p, q*o.q);
	}
	
	frac operator / (frac o){
		return frac(p*o.q, q*o.p);
	}
	
	bool operator<(const frac &o) const{ return p*o.q < o.p*q; }
	bool operator>(const frac &o) const{ return p*o.q > o.p*q; }
	bool operator==(frac o){ return p==o.p && q==o.q; }
	
};

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long a, b, n; cin >> a >> b >> n;
	
	
	ii dir = {frac(a,b).q,frac(a,b).p};
	pair<frac,frac> pos = {frac(-1,1), frac(0,1)};
	
	frac one = frac(1,1), mone = frac(-1,1), zer = frac(0,1);
	
	forn(N,n+1){
		frac ti = frac(-1,1);
		pair<frac,frac> inter;
		ii ndir;
		
		frac fdirx = frac(dir.x,1), fdiry = frac(dir.y,1);
		
		frac cti = (mone-pos.x)/fdirx;
		if(cti > zer && (ti<zer || ti>cti)){ // left
 			ti = cti;
			
			ndir.x = dir.x*-1;
			ndir.y = dir.y;
			
			inter.x = mone;
			inter.y = pos.y + fdiry*ti;
		}
		
		cti = (one-pos.x)/fdirx;
		if(cti > zer && (ti<zer || ti>cti)){ // right
			ti = cti;
			
			ndir.x = dir.x*-1;
			ndir.y = dir.y;
			
			inter.x = one;
			inter.y = pos.y + fdiry*ti;
		}
		
		cti = (mone-pos.y)/fdiry; 
		if(cti > zer && (ti<zer || ti>cti)){ // bottom
			ti = cti;
			
			ndir.x = dir.x;
			ndir.y = dir.y*-1;
			
			inter.x = pos.x + fdirx*ti;
			inter.y = mone;
		}
		
		cti = (one-pos.y)/fdiry; 
		if(cti > zer && (ti<zer || ti>cti)){ // top
			ti = cti;
			
			ndir.x = dir.x;
			ndir.y = dir.y*-1;
			
			inter.x = pos.x + fdirx*ti;
			inter.y = one;
		}
		
		pos = inter;
		dir = ndir;
		
		pos.fst.norm();
		pos.snd.norm();
	}
	
	if(pos.fst.q < 0){
		pos.fst.q *= -1;
		pos.fst.p *= -1;
	}
	
	if(pos.fst == zer){
		pos.fst = zer;
	}
	
	if(pos.snd.q < 0 ){
		pos.snd.q *= -1;
		pos.snd.p *= -1;
	}
	
	if(pos.snd == zer){
		pos.snd = zer;
	}
	
	cout << (long long) pos.fst.p << " " << (long long) pos.fst.q << " " << (long long) pos.snd.p << " " << (long long) pos.snd.q << "\n";
	
	return 0;
}
