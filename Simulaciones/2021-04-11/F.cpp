#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP
#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long double n,p;
	cin>>n>>p;
	double m = floor(n/(p-1.0));
	double fact=1.0,ans=m*p;
	forr(i,1,n+m+1){
		fact=double(i);
		if(i<=n) ans*=fact;
		if(i<=m+n-p) ans*=fact;
		if(i<=n-p+1) ans/=fact;
		if(i<=m+n) ans/=fact;
	}
	cout<<fixed<<setprecision(7)<<ans<<"\n";
	
	return 0;
}
