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
const ll MOD = 1000000007;
#define mod(x,y) ((x%MOD + y%MOD)%MOD+MOD)%MOD
ll dp[10010][760];
ll L,n,k;


int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>k>>L;
	vector<vector<ll>> T(k);
	forn(i,k){ T[i].resize(k); forn(j,k) cin>>T[i][j];}
	
	cin>>n;
	vector<ll> P(n-1);
	forn(i,n-1) cin>>P[i];
	
	forn(i,n+5) forn(j,k+5) dp[i][j]=0;
	forn(i,k) dp[n-1][i]=1LL;
	
	dforn(i,n-1){
		forr(j,1,k) dp[i+1][j]= mod(dp[i+1][j],dp[i+1][j-1]);
		forn(j,k){
			ll l=lower_bound(T[j].begin(),T[j].end(),P[i]-L)-T[j].begin()-1,r=upper_bound(T[j].begin(),T[j].end(),P[i]+L)-T[j].begin()-1;
			if(r==-1) dp[i][j]=0;
			else if(l==-1) dp[i][j]=dp[i+1][r];
			else{
				dp[i][j] = mod(dp[i+1][r],-dp[i+1][l]);
			}
		}
	}
	ll ans=0;
	forn(i,k) ans = mod(ans,dp[0][i]);
	cout<<(ans+MOD)%MOD<<"\n";
	
	return 0;
}




