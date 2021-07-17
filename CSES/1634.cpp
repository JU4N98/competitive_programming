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
int dp[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,x;
	cin>>n>>x;
	vector<int> arr(n);
	forn(i,n) cin>>arr[i];
	forn(i,x+1) dp[i]=INT_MAX;
	dp[x]=0;
	dforn(i,x+1) if(dp[i]!=INT_MAX) forn(j,n) if(i-arr[j]>=0) dp[i-arr[j]]=min(dp[i-arr[j]],dp[i]+1);
	if(dp[0]==INT_MAX) cout<<"-1\n";
	else cout<<dp[0]<<"\n";
	
	return 0;
}




