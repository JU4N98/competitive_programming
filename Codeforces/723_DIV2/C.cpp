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
ll dp[2010][2010];

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin>>n;
	vector<ll> arr(n);
	forn(i,n) cin>>arr[i];
	
	forn(i,n+1) forn(j,n+1) dp[i][j]=-1;
	forn(i,n+1) if(arr[i]>=0) dp[i+1][1]=arr[i];
	
	forn(i,n){
		forn(j,n+1){
			if(dp[i][j]>=0){
				if(dp[i][j]+arr[i]>=0) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+arr[i]);
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			}
		}
	}
	ll ans=0;
	forn(i,n+1) if(dp[n][i]!=-1) ans=i;
	cout<<ans<<"\n";
	
	return 0;
}




