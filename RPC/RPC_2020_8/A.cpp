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
//#define ANARAP
#define MAXN 1048576
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
const tf MOD=2305843009255636993, RT=5;

struct CD{
	double r,i;
	CD(double r=0,double i=0): r(r), i(i){}
	double real() const {return r;}
	void operator /=(const int c) {r/=c,i/=c;}
};
CD operator*(const CD& a, const CD& b){return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi = acos(-1.0);

CD cp1[MAXN+9], cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	forr(i,0,n) if(R[i]<i) swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv? -1:1);
		CD wi=CD(cos(z),sin(z));
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k]; CD v=a[k2]*w; a[k]=u+v; a[k2]=u-v; w=w*wi;
			}
		}
	}
	if(inv) forr(i,0,n) a[i]/=n;
}

poly multiply(poly& p1, poly& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n) m+=m,cnt++;
	forr(i,0,m){R[i]=0;forr(j,0,cnt) R[i]=(R[i]<<1)|((i>>j)&1);}
	forr(i,0,m) cp1[i]=0,cp2[i]=0;
	forr(i,0,p1.size()) cp1[i]=p1[i];
	forr(i,0,p2.size()) cp2[i]=p2[i];
	dft(cp1,m,false); dft(cp2,m,false);
	forr(i,0,m) cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	forr(i,0,n) res.pb((tf) floor(cp1[i].real()+0.5));
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
	
	string a,b;
	while(cin>>a){
		cin>>b;
		poly pa,pb;
		char gataca[4]= {'G','A','T','C'};
		poly res;
		forn(j,4){
			forn(i,a.size()) if(a[i]==gataca[j]) pa.pb(1LL); else pa.pb(0);
			forn(i,b.size()) if(b[i]==gataca[j]) pb.pb(1LL); else pb.pb(0);
			reverse(pb.begin(),pb.end());
			if(j==0) res=multiply(pa,pb);
			else{
				poly res2 = multiply(pa,pb);
				forn(i,res.size()) res[i]+=res2[i];
			}
			pa.clear();
			pb.clear();
		}
		ll maxi=0,pos;
		forn(i,res.size()){
			if(res[i]>=maxi){
				maxi=res[i];
				pos=i;
			}
		}
		cout<<maxi<<"\n";
		if(maxi==0) cout<<"No matches\n\n";
		else{
			string aux;
			forn(i,b.size()) aux += "?";
			a=aux+a+aux;
			string bux;
			forn(i,pos+1) bux += "?";
			b=bux+b;
			forr(i,b.size(),a.size()) b+='?';
			forn(i,b.size()){
				if(a[i]=='?' && b[i]=='?') continue;
				if(a[i]==b[i]) cout<<a[i];
				else if(a[i]=='?') cout<<b[i];
				else if(b[i]=='?') cout<<a[i];
				else cout<<"X";
			}
			cout<<"\n\n";
		}
		
	}
	
	
	return 0;
}




