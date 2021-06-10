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
		vector<ll> arr(n),mm(n);
		forn(i,n) cin>>arr[i];
		mm=arr;
		sort(mm.begin(),mm.end());
		ll mini,maxi;
		forn(i,n){
			if(arr[i]==mm[0]) mini=i;
			if(arr[i]==mm[n-1]) maxi=i;
		}
		ll mai = max(maxi,mini), mii=min(maxi,mini);
		ll ans=LLONG_MAX;
		ans=min(mai+1,ans);
		ans=min(n-mii,ans);
		ans=min(mii+1+n-mai,ans);
		cout<<ans<<"\n";
	}
	
	return 0;
}




