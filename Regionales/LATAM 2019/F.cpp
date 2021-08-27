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
const int mod = 1000000007;
int dp[5001][5001];

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int s,b;
	cin>>s>>b;
	
	forn(i,s+1){
		forn(j,b+1){
			dp[i][j]=0;
		}
	}
	forn(i,b+1) dp[1][i]=1;
	forn(i,s+1) dp[i][0]=1;
	
	b-=s;
	forr(bi,1,b+1){
		int act = 1;
		forr(si,2,s+1){
			dp[si][bi]=dp[si-1][bi];
			if(bi-si>=0) act=((act+dp[si][bi-si])%mod+mod)%mod;
			dp[si][bi]=((dp[si][bi]+act)%mod+mod)%mod;
		}
	}
	
	cout<<dp[s][b]<<"\n";
	
	return 0;
}




