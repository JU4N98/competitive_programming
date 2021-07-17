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
const int MOD = 1e9+7;
int dp[1001][1001];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<string> mat(n);
	forn(i,n) cin>>mat[i];
	forn(i,n) forn(j,n) dp[i][j]=0;
	if(mat[0][0]!='*') dp[0][0]=1;
	forn(i,n){
		forn(j,n){
			if(dp[i][j]!=0){
				if(j+1<n && mat[i][j+1]!='*') dp[i][j+1]=(dp[i][j+1]%MOD+dp[i][j]%MOD)%MOD;
				if(i+1<n && mat[i+1][j]!='*') dp[i+1][j]=(dp[i+1][j]%MOD+dp[i][j]%MOD)%MOD;
			}
		}
	}
	cout<<dp[n-1][n-1]<<"\n";
	
	return 0;
}




