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
ll dp[71][71][71][71], mat[71][71];

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll n,m,k;
	cin>>n>>m>>k;
	
	forn(i,71) forn(j,71) forn(l,71) forn(h,71) dp[i][j][l][h]=LLONG_MIN; 
	forn(i,n) forn(j,m) cin>>mat[i][j];
	
	dp[0][0][0][0]=0;
	forn(i,n){
		forn(j,m){
			forn(l,k){
				forn(h,m/2+1){
					if(dp[i][j][l][h]>LLONG_MIN){
						if(h<m/2){
							dp[i][j+1][(l+mat[i][j])%k][h+1]=max(dp[i][j+1][(l+mat[i][j])%k][h+1],dp[i][j][l][h]+mat[i][j]);
							dp[i+1][0][(l+mat[i][j])%k][0]=max(dp[i+1][0][(l+mat[i][j])%k][0],dp[i][j][l][h]+mat[i][j]);
						}
						dp[i][j+1][l][h]=max(dp[i][j+1][l][h],dp[i][j][l][h]);
						dp[i+1][0][l][0]=max(dp[i+1][0][l][0],dp[i][j][l][h]);
					}
				}
			}
		}
	}
	
	
	
	cout<<dp[n][0][0][0]<<"\n";
	
	return 0;
}
