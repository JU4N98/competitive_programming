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
const int MOD=998244353,RT=3,MAXN=(1<<22);

typedef vector<ll> poly;

struct CD {
	double r,i;
	CD(double r=0, double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1.0);


CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	forr(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv?-1:1); // FFT
		CD wi=CD(cos(z),sin(z)); // FFT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)forr(i,0,n)a[i]/=n; 
}
poly multiply(poly& p1, poly& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	forr(i,0,m){R[i]=0;forr(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	forr(i,0,m)cp1[i]=0,cp2[i]=0;
	forr(i,0,p1.size())cp1[i]=p1[i];
	forr(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	forr(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	forr(i,0,n)res.pb((ll)floor(cp1[i].real()+0.5)); 
	return res;
}

vector<ll> solve(poly arr, int k){
	vector<ll> ans; ans.pb(1);
	poly pot = arr;
	
	while(k>0){
		if(k&(1)) ans = multiply(pot,ans);
		
		pot = multiply(pot,pot);	
		
		forn(i,sz(pot)) pot[i] > 0 ? pot[i] = 1 : pot[i] = 0;
		forn(i,sz(ans)) ans[i] > 0 ? ans[i] = 1 : ans[i] = 0;
		
		k/=2;
	}
	return ans;
}


int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,k; cin >> n >> k;
	vector<ll> val(1010);
	
	forn(i,n){
		int pos; cin >> pos;
		val[pos] = 1;
	}
	
	vector<ll> ans = solve(val,k);
	forr(i,1,sz(ans)) if(ans[i]) cout << i << " ";
	cout << "\n";
	
	return 0;
}
