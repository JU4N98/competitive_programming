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
#define x first
#define y second

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
const tf MAXN=262144,RT=5;

// FFT
struct CD {
	long double r,i;
	CD(long double r=0, long double i=0):r(r),i(i){}
	long double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const long double pi=acos(-1.0);

CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	forr(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		long double z=2*pi/m*(inv?-1:1); // FFT
		CD wi=CD(cos(z),sin(z)); // FFT
		// CD wi=root(m,inv); // NTT
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
	forr(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5));
	return res;
}

vector<ll> calc(vector<ll> f, vector<ll> c){
	sort(f.begin(),f.end());
	sort(c.begin(),c.end());
	vector<ll> ans;
	
	ll cur = 0;
	vector<ll> fft_f, fft_c, rem;
	
	forn(i,sz(f)){
		if((f[i]<0 && c[i]>0) || (f[i]>0 && c[i]<0)){
			fft_f.pb(f[i]); fft_c.pb(c[i]); 
		}else{
			rem.pb(f[i]*c[i]);
			cur += f[i]*c[i];
		}
	}
	
	if(sz(fft_c)>0){
		if(fft_c[0]<0) reverse(fft_c.begin(),fft_c.end());
		else reverse(fft_f.begin(),fft_f.end());
		poly poly_f = fft_f, poly_c = fft_c, mult;
		mult = multiply(poly_f,poly_c);
		
		//~ cout << sz(mult) << " " << sz(fft_f)-1 << "\n";
		//~ forn(i,sz(mult)) cout << mult[i] << " ";
		//~ cout << sz(fft_f) << " " << sz(mult) << endl;
		//~ cout << "\n";
		dforn(i,sz(fft_f)){
			ans.pb(cur+mult[i]);
		}
	}
	
	sort(rem.begin(),rem.end());
	ans.pb(cur);
	forn(i,sz(rem)-1){
		cur-=rem[i];
		ans.pb(cur);
	}
	
	//~ cout << ans[0];
	//~ forr(i,1,sz(ans)) cout << " " << ans[i];
	//~ cout << "\n";
	
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
	
	int n; cin >> n;
	vector<ll> f(n),c(n);
	forn(i,n) cin >> f[i];
	forn(i,n) cin >> c[i];
	
	vector<ll> maxi = calc(f,c);
	forn(i,n) f[i] *= -1;
	vector<ll> mini = calc(f,c);
	
	dforn(i,n){
		cout << -mini[i] << " " << maxi[i] << "\n";
	}
	
	return 0;
}
