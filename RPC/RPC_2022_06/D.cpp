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

typedef int tf;
typedef vector<tf> poly;
const ll MAXN = 33554432;

// FFT
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

vector<CD> cp1, cp2;
int R[MAXN+9];
void dft(vector<CD> & a, int n, bool inv){
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
	forr(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5)); // FFT
	return res;
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
	string enc, des; cin >> enc >> des;
	
	cp1.resize(MAXN+9);
	cp2.resize(MAXN+9);
	
	poly p, t;
	p.reserve(26*n*2);
	t.reserve(26*n*2*2);
	forn(i,sz(enc)){
		forn(j,26) p.pb(enc[i]-'a' == j);
		forn(j,26) p.pb(0);
	}
	reverse(p.begin(),p.end());
	
	//~ forn(i,sz(p)) cout << p[i] << " ";
	//~ cout << "\n";
	
	des += des;
	forn(i,sz(des)){
		forn(j,26) t.pb(des[i]-'a' == j);
		forn(j,26) t.pb(des[i]-'a' == j);
	}
	
	//~ forn(i,sz(t)) cout << t[i] << " ";
	//~ cout << "\n";
	
	poly mul = multiply(p,t);
	
	//~ forn(i,sz(mul)){
		//~ cout << mul[i] << " ";
	//~ }
	//~ cout << "\n\n";
	
	int ans = 0; 
	forn(i,n){
		forn(j,26){
			ans = max(ans,mul[2*n*26+i*2*26+j]);
		}
	}
	
	ll szi = sz(enc);
	
	cout << szi - ans << endl;
	
	return 0;
}




