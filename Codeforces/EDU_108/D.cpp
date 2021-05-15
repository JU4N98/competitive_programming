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
ll dp[5010][5010],a[5000],b[5000],pre[5010],suf[5010];
ll n;

ll solve(ll i,ll j){
	if(dp[i][j]==-1){
		if(i==j){
			dp[i][j]=a[i]*b[i];
		}else if(abs(i-j)==1){
			dp[i][j]=a[i]*b[j] + a[j]*b[i];
		}else{
			dp[i][j]=a[i]*b[j]+a[j]*b[i]+solve(i+1,j-1);
		}
	}
	return dp[i][j];
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	forn(i,n) cin>>a[i];
	forn(i,n) cin>>b[i];
	
	forn(i,n) forn(j,n) dp[i][j]=-1;
	pre[0]=0;
	forn(i,n) pre[i+1]=pre[i]+a[i]*b[i];
	suf[n]=0;
	dforn(i,n) suf[i]=suf[i+1]+a[i]*b[i];
	
	//~ forn(i,n+1) cout<<pre[i]<<" ";
	//~ cout<<endl;
	//~ forn(i,n+1) cout<<suf[i]<<" ";
	//~ cout<<endl;
	
	ll ans=0;
	forn(i,n) ans+=a[i]*b[i];
	forn(i,n){
		forn(j,n){
			if(j>=i){
				dp[i][j]=solve(i,j);
				ans=max(ans,dp[i][j]+pre[i]+suf[j+1]);
			}
			//~ cout<<dp[i][j]<<"	";
		}
		//~ cout<<endl;
	}
	cout<<ans<<endl;
	
	return 0;
}




