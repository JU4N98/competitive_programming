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
#else
	
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
const int MOD = 1e9+7;
int dp[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x,n;
	cin>>n>>x;
	vector<int> arr(n);
	forn(i,n) cin>>arr[i];
	sort(arr.begin(),arr.end());
	
	forn(j,x+1) dp[j]=0;
	
	forn(j,n){
		dp[arr[j]]+=1;
		forn(i,x+1){
			if(dp[i]!=0 && i+arr[j]<=x) dp[i+arr[j]]=(dp[i+arr[j]]%MOD+dp[i]%MOD)%MOD;
		}
	}
	
	cout<<dp[x]<<"\n";
	
	
	return 0;
}




