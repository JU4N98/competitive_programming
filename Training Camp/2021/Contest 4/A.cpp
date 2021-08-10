#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) forr(i,a,b)
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
const ll mod = 1000000007; 
vector<vector<ll>> G;
vector<ll> dp;
vector<ll> tam;

ll dfs(ll u){
	tam[u]=1;
	forn(i,sz(G[u])) tam[u]+=dfs(G[u][i]);
	return tam[u];
}

ll solve(ll u, ll cantdisp){
	if(G[u].size()==0){
		dp[u]=cantdisp;
	}else{
		dp[u]=max(cantdisp-(tam[u]-1),0LL);
		forn(i,sz(G[u])){
			ll v = G[u][i];
			dp[u] = ((dp[u]%mod) * (solve(v,cantdisp-tam[u]+tam[v])%mod))%mod;
		}
	}
	return dp[u];
}

typedef ll tf;
typedef vector<tf> poly;
const tf MOD=2305843009255636993,RT=5;
// FFT
//~ struct CD {
	//~ double r,i;
	//~ CD(double r=0, double i=0):r(r),i(i){}
	//~ double real()const{return r;}
	//~ void operator/=(const int c){r/=c, i/=c;}
//~ };
//~ CD operator*(const CD& a, const CD& b){
	//~ return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
//~ CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
//~ CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
//~ const double pi=acos(-1.0);
// NTT

ll mulmod(ll a,ll b) //O(log b)
{ //returns (a*b) %c, and minimize overfloor
	ll x=0, y=a%mod;
	while(b>0)
	{
		if(b%2==1) x=(x+y)%mod;
		y=(y*2)%mod;
		b/=2;
	}
	return x%mod;
}

ll addmod(ll a,ll b)
{
	a%=mod;
	b%=mod;
	if(a<0) a+=mod;
	if(b<0) b+=mod;
	return (a+b)%mod;
}

ll submod(ll a,ll b)
{
	a%=mod;
	b%=mod;
	if(a<0) a+=mod;
	if(b<0) b+=mod;
	ll ret=a-b;
	if(ret<0) ret+=mod;
	return ret;
}

struct CD {
	tf x;
	CD(tf x):x(x){}
	CD(){}
};
CD operator*(const CD& a, const CD& b){return CD(mulmod(a.x,b.x));}
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
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
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
	//~ if(inv)fore(i,0,n)a[i]/=n; // FFT
	if(inv){ // NTT
		CD z(pm(n,MOD-2)); // pm: modular exponentiation
		fore(i,0,n)a[i]=a[i]*z;
	}
}
poly multiply(poly& p1, poly& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	fore(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	fore(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5)); // FFT
	//fore(i,0,n)res.pb(cp1[i].x); // NTT
	return res;
}

poly add(poly &a, poly &b){
	int n=SZ(a),m=SZ(b);
	poly ans(max(n,m));
	fore(i,0,max(n,m)){
		if(i<n) ans[i]=addmod(ans[i],a[i]);
		if(i<m) ans[i]=addmod(ans[i],b[i]);	
	}
	while(SZ(ans)>1&&!ans.back())ans.pop_back();
	return ans;
}

poly interpolate(vector<tf> &x, vector<tf> &y){
	filltree(x);
	poly p=derivate(tree[1]);
	int k=SZ(y);
	vector<tf> d=evaluate(p,x);
	vector<poly> intree(2*k);
	fore(i,k,2*k) intree[i]={mulmod(y[i-k],inv(d[i-k]))};
	for(int i=k-1;i;i--){
		poly p1=multiply(tree[2*i],intree[2*i+1]);
		poly p2=multiply(tree[2*i+1],intree[2*i]);
		intree[i]=add(p1,p2);
	}
	return intree[1];
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	ll n,d;
	cin>>n>>d;
	
	vector<ll> yi(n+3);
	
	
	//~ G.resize(n);
	//~ tam.resize(n);
	//~ dp.resize(n,-1);
	//~ forn(u,n-1){
		//~ ll v; cin>>v;
		//~ G[v-1].pb(u+1);
	//~ }
	//~ dfs(0);
	//~ cout<<solve(0,d)<<"\n";
	
	return 0;
}




