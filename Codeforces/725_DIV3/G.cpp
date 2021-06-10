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



bool check(ll x1,ll x2, ll x, ll y, ll a, ll b){
	return (x1*a+x2*b<=x) && (x1*b+x2*a<=y);
}

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
		long double x,y,a,b;
		cin>>x>>y>>a>>b;
		long double x1,x2;
		x1=(y/a-x/b)/(b/a-a/b);
		x2=(-b/a)*x1+(y/a);
		ll ans=0;
		if(x1>=0 && x2>=0){
			ans = floor(x1)+floor(x2);
			if(check(floor(x1),ceil(x2),floor(x),floor(y),floor(a),floor(b))){
				ll aux=floor(x1)+ceil(x2);
				ans=max(ans,aux);
			}if(check(ceil(x1),floor(x2),floor(x),floor(y),floor(a),floor(b))){
				ll aux = ceil(x1)+floor(x2);
				ans=max(ans,aux);
			}
		}
		ll lx=floor(x),ly=floor(y),la=floor(a),lb=floor(b);
		ans = max(ans,min(lx/la,ly/lb));
		ans=max(ans,min(lx/lb,ly/la));
		cout<<ans<<"\n";
	}
	
	return 0;
}




