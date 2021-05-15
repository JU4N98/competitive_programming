#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0; i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end(); it++)
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

#else

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
	
	ll n;
	cin>>n;
	vector<ll> arr(n),ans;
	forn(i,n) cin>>arr[i];
	sort(arr.begin(),arr.end());
	forn(i,n/2){
		ans.pb(arr[i]);
		ans.pb(arr[n-i-1]);
	}
	if(n%2==1) ans.pb(arr[n/2]);
	reverse(ans.begin(),ans.end());
	forn(i,n) cout<<ans[i]<<" ";
	cout<<"\n";

	
	
	return 0;
}
