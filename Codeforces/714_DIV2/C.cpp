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
const int MOD = 1000000007;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll dp[210000][10][2];
	ll n,m=201000;
	forn(j,10){
		n=j;
		forn(i,m+1000) dp[i][j][0]=0,dp[i][j][1]=0;
		
		dp[10-(n%10)][j][0]++;
		dp[10-(n%10)][j][1]++;
		
		forn(i,m){
			if(9+i>m){
				dp[m][j][1]=(dp[m][j][1]+dp[i][j][1])%MOD;
			}else{
				dp[9+i][j][0]=(dp[9+i][j][0]+dp[i][j][1])%MOD;
				dp[9+i][j][1]=(dp[9+i][j][1]+dp[i][j][1])%MOD;
			}
			if(10+i>m){
				dp[m][j][0]=(dp[m][j][0]+dp[i][j][0])%MOD;
			}else{
				dp[10+i][j][0]=(dp[10+i][j][0]+dp[i][j][0])%MOD;
				dp[10+i][j][1]=(dp[10+i][j][1]+dp[i][j][0])%MOD;
			}
		}
	}
	/*
	forn(i,10){
		cout<<"I "<<i<<endl;
		forn(j,11){
			forn(k,2){
				cout<<dp[j][i][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<endl;
	* */
	ll t;
	cin>>t;
	forn(T,t){
		cin>>n>>m;
		ll ans=0;
		vector<ll> aux(10,0);
		forn(i,10){
			forn(j,9){
				if(m-j>=0){
					aux[i] = (aux[i]+dp[m-j][i][0])%MOD;
					aux[i] = (aux[i]+dp[m-j][i][1])%MOD;
				}
			}
			if(m-9>=0) aux[i] = (aux[i]+dp[m-9][i][0])%MOD;
			if(aux[i]==0) aux[i]=1;
		}
		while(n>0){
			ans = (ans+aux[n%10])%MOD;
			n/=10;
		}
		cout<<ans%MOD<<"\n";
	}
	
	
	return 0;
}




