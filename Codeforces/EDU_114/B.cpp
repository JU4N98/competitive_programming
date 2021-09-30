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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t; cin>>t;
	forn(T,t){
		vector<ll> arr(3); cin>>arr[0]>>arr[1]>>arr[2];
		ll m; cin>>m;
		sort(arr.begin(),arr.end());
		ll maxi = arr[0]+arr[1]+arr[2]-3;
		ll mini = arr[2]-1-arr[1]-arr[0];
		if(mini<=m && maxi>=m) cout<<"YES\n";
		else cout<<"NO\n";
		
	}
	
	return 0;
}




