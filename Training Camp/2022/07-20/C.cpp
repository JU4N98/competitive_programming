#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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
int dp[3010][2];


int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<int> a(n), b(n), c(n);
	
	forn(i,n) cin >> a[i];
	forn(i,n) cin >> b[i];
	forn(i,n) cin >> c[i];
	
	forn(i,n+1){
		forn(j,2){
			dp[i][j] = -1;
		}
	}
	
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	
	forr(i,1,n){
		dp[i][0] = max(dp[i-1][1]+a[i], dp[i-1][0]+b[i]);
		dp[i][1] = max(dp[i-1][1]+b[i], dp[i-1][0]+c[i]);
	}
	
	cout << max(dp[n-1][0],dp[n-1][1]) << "\n";
	
	return 0;
}




