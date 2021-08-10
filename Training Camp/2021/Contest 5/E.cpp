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


int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<vector<int>> dp(101);
	forn(i,101) dp[i].resize(2501,0);
	forn(i,26) dp[0][i]=1;
	
	forn(i,100){
		forn(j,2501){
			forn(k,26){
				if(j+k<2501) dp[i+1][j+k] = (dp[i+1][j+k]+dp[i][j])%mod;
			}
		}
	}
	
	int t; cin>>t;
	forn(T,t){
		string s; cin>>s;
		int tam=sz(s),sum=0;
		forn(i,sz(s))sum+=s[i]-'a';
		cout<<dp[tam-1][sum]-1<<"\n";
	}
	
	return 0;
}




