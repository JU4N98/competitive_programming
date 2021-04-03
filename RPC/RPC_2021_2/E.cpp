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
#define ANARAP

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll r,c,n;
	cin>>r>>c>>n;
	vector<vector<ll>> mat(r);
	vector<vector<bool>> usable(r),pase(r);
	
	forn(i,r){
		mat[i].resize(c);
		usable[i].resize(c,true);
		forn(j,c){
			cin>>mat[i][j];
			if(mat[i][j]==-1) usable=false;
		}
	}
	
	
	forn(i,r){
		pase[i].resize(c,false);
		if(i!=0 && i!=r-1){
			forn(j,c){
				if(j!=0 && j!=c-1){
					if(mat[i+1][j]>mat[i][j] && mat[i-1][j]>mat[i][j]
					&& mat[i][j]>mat[i][j-1] && mat[i][j]>mat[i][j+1]) pase=true;
				}
			}
		}
	}
	
	ll dp[510][510][15];
	forr(i,0,r) forr(j,0,c+1) forr(k,0,n+1) dp[i][j][k]=LLONG_MAX;
	forr(i,0,r) dp[i][0][0]=0;
	
	forn(i,r){
		forn(j,c){
			forn(k,n+1){
				if(dp[i][j][k]!=LLONG_MAX && k<=n){
					if(i>0){
						if(usable[i-1][j+1]){
							if(pase[i-1][j+1]){
								dp[i-1][j+1][k+1] = min(dp[i-1][j+1][k+1], dp[i][j][k]+mat[i-1][j+1][k+1]);
							}else{
								dp[i-1][j+1][k] = min(dp[i-1][j+1][k], dp[i][j][k]+mat[i-1][j+1][k]);
							}
						}
					}
					if(usable[i][j+1]){
						if(pase[i][j+1]){
							dp[i][j+1][k+1] = min(dp[i][j+1][k+1], dp[i][j][k]+mat[i][j+1][k]);
						}else{
							
						}
					}
					if(i<r-1){
						if(usable[i+1][j+1]){
							if(pase[i+1][j+1]){
								
							}else{
								
							}
						}
					}
				}
			}
		}
	}
	
	
	return 0;
}




