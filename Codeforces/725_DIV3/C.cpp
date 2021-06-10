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
typedef pair<ll,ll> ii;

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
		ll n,l,r;
		cin>>n>>l>>r;
		vector<ll> arr(n);
		forn(i,n) cin>>arr[i];
		sort(arr.begin(),arr.end());
		ll ans=0;
		forn(i,n){
			ans+=upper_bound(arr.begin()+i+1,arr.end(),r-arr[i])-lower_bound(arr.begin()+i+1,arr.end(),l-arr[i]);
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}




