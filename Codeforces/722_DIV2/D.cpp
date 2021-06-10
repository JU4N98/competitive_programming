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
const ll MOD = 998244353;
ll dp[2000010];

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
	forn(i,n*2+1) dp[i]=1;
	forr(i,2,2*n+1){
		if(i*2<=n*2) dp[i*2]=(dp[i]%MOD+dp[i*2]%MOD)%MOD;
		if(i+4<=n*2) dp[i+4]=(dp[i]%MOD+dp[i+4]%MOD)%MOD;
		if(i+2<=n*2) dp[i+2]=(dp[i]%MOD+dp[i+2]%MOD)%MOD;
		//forn(i,2*n+1) cout<<dp[i]<<" ";
		//cout<<"\n";
	}
	cout<<dp[n*2]%MOD<<"\n";
	
	return 0;
}




