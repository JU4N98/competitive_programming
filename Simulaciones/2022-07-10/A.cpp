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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

// MAXN must be power of 2 !!
// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
typedef ll tf;
typedef vector<tf> poly;
const tf MOD=998244353,RT=5;
const tf MAXN = 262144;

ll addmod(ll a, ll b){
	return (a+b)%MOD;
}

ll submod(ll a, ll b){
	return (a-b+MOD)%MOD;
}

ll pm(ll b,ll e,ll m=MOD){
	if(!e) return 1;
	ll q=pm(b,e/2,m);
	q = (q * q)%MOD;
	return e%2? (b*q)%MOD : q;
}

ll inverso(ll x){ //O(log x){
	return pm(x, MOD-2);//si mod es primo
}

// NTT
struct CD {
	tf x;
	CD(tf x):x(x){}
	CD(){}
};
CD operator*(const CD& a, const CD& b){return CD(a.x * b.x % MOD);}
CD operator+(const CD& a, const CD& b){return CD(addmod(a.x,b.x));}
CD operator-(const CD& a, const CD& b){return CD(submod(a.x,b.x));}

vector<tf> rts(MAXN+9,-1);
CD root(int n, bool inv){
	tf r=rts[n]<0?rts[n]=pm(RT,(MOD-1)/n):rts[n];
	return CD(inv?pm(r,MOD-2):r);
}

CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	forr(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		//~ double z=2*pi/m*(inv?-1:1); // FFT
		//~ CD wi=CD(cos(z),sin(z)); // FFT
		CD wi=root(m,inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	//~ if(inv)forr(i,0,n)a[i]/=n; // FFT
	if(inv){ // NTT
		CD z(pm(n,MOD-2)); // pm: modular exponentiation
		forr(i,0,n)a[i]=a[i]*z;
	}
}

poly multiply(poly& p1, poly& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	forr(i,0,m){R[i]=0;forr(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	forr(i,0,m)cp1[i]=0,cp2[i]=0;
	forr(i,0,p1.size())cp1[i]=p1[i];
	forr(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false); dft(cp2,m,false);
	forr(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	//~ forr(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5)); // FFT
	forr(i,0,n)res.pb(cp1[i].x); // NTT
	return res;
}

poly solve(vector<tf> &acc, int l, int r){
	if(l == r){
		assert(l<sz(acc));
		poly base(2);
		base[0] = 1;
		base[1] = acc[l];
		return base;
	}else{
		int med = (l+r)/2;
		poly left = solve(acc,l,med);
		poly right = solve(acc,med+1,r);
		return multiply(left,right);
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
	
	vector<tf> fact(100010);
	fact[0] = 1;
	forr(i,1,100010) fact[i] = (fact[i-1]*i)%MOD;
	vector<tf> inv(100010);
	forr(i,1,100010) inv[i] = inverso(fact[i]);
	
	int t; cin >> t;
	forn(T,t){
		int n; cin >> n;
		
		int r = 1; while(r<n) r*=2;
		poly acc(r);
		forn(N,n) cin >> acc[N];
		
		ll ans = 0;
		poly sums = solve(acc,0,r-1);
		forr(i,1,n+1){
			ans = (ans + (sums[i] * fact[i] % MOD * fact[n-i] % MOD * inv[n] % MOD))%MOD; 
		}
		cout << ans << endl;
	}
	
	return 0;
}




