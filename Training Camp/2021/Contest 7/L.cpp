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
int dp[3010][100][2];

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,l; cin>>n>>l;
	vector<ii> arr;
	forn(i,n){
		int a,b; cin>>a>>b;
		arr.pb({min(a,b),max(a,b)});
	}
	sort(arr.begin(),arr.end());
	
	forn(i,3010) forn(j,sz(arr)) forn(k,2) dp[i][j][k]=-1;
	
	forn(i,sz(arr)){
		//~ cout<<arr[i].fst<<" "<<i<<" "<<0<<endl;
		dp[arr[i].fst][i][0]=1;
		if(arr[i].snd!=arr[i].fst) dp[arr[i].snd][i][1]=1;
	}
	
	forn(i,l){
		forn(j,sz(arr)){
			forn(k,2){
				if(dp[i][j][k]!=-1){
					forn(j2,sz(arr)){
						if(j2==j) continue;
						int w=0; k == 0? w=arr[j].snd : w = arr[j].fst;
						if(i+arr[j2].fst<=l && arr[j2].fst==w){
							if(dp[i+arr[j2].fst][j2][0]==-1) dp[i+arr[j2].fst][j2][0]=0;
							dp[i+arr[j2].fst][j2][0] = ((dp[i+arr[j2].fst][j2][0] + dp[i][j][k])%mod+mod)%mod;
						}
						if(i+arr[j2].snd<=l && arr[j2].snd!=arr[j2].fst && arr[j2].snd==w){
							if(dp[i+arr[j2].snd][j2][1]==-1) dp[i+arr[j2].snd][j2][1]=0;
							dp[i+arr[j2].snd][j2][1] = ((dp[i+arr[j2].snd][j2][1] + dp[i][j][k])%mod+mod)%mod;
						}
					}
				}
			}
		}
	}
	
	int ans=0;
	forn(i,sz(arr)){
		forn(k,2){
			//~ cout<<"dp["<<l<<"]["<<i<<"]["<<k<<"] = "<<max(dp[l][i][k],0LL)<<endl;
			dp[l][i][k]=max(dp[l][i][k],0);
			ans = ((ans+dp[l][i][k])%mod+mod)%mod;
		}
	}
	cout<<ans<<"\n";
	
	
	
	return 0;
}




