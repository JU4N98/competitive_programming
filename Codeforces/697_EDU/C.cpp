#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b; a<c; a++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define ll long long
//#define ANARAP
ll dp[202][402];


int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		cin>>n;
		vector<ll> platos;
		platos.resize(n);
		forn(j,n) cin>>platos[j];
		sort(platos.begin(),platos.end());
		forn(j,202) forn(k,402) dp[j][k]=LLONG_MAX;
		dp[0][0]=0;
		forn(j,n+1){
			forn(k,2*n+1){
				if(dp[j][k]<LLONG_MAX){
					if(j<n){
						dp[j+1][k+1]=min(dp[j+1][k+1],dp[j][k]+abs(platos[j]-k-1));
					}
					dp[j][k+1]=min(dp[j][k+1],dp[j][k]);
				}
			}
		}
		cout<<dp[n][2*n]<<"\n";
	}
	
	
	return 0;
}
