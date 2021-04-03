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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		vector<ll> c(n),adi(n);
		forn(i,n) cin>>c[i];
		ll acum=c[0], minpar=c[0], minimp=LLONG_MAX, canti=0, cantp=1;
		ll ans = LLONG_MAX;
		forr(i,1,n){
			if(i%2==1){
				minimp = min(minimp,c[i]);
				canti++;
			}else{
				minpar = min(minpar,c[i]);
				cantp++;
			}
			acum+=c[i];
			ans = min((n-canti)*minimp+(n-cantp)*minpar+acum,ans);
		}
		cout<<ans<<"\n"; 
		 
	}
	
	return 0;
}




