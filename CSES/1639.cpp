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
 
int dp[5002][5002];
string a,b;
 
int solve(int posa, int posb){
	if(dp[posa][posb]==-1){
		if(posa==sz(a) && posb==sz(b)){
			dp[posa][posb] = 0;
		}else if(posa==sz(a)){
			dp[posa][posb]=sz(b)-posb;
		}else if(posb==sz(b)){
			dp[posa][posb]=sz(a)-posa;
		}else{
			dp[posa][posb]=min(min(solve(posa+1,posb),solve(posa,posb+1)),solve(posa+1,posb+1))+1; //elimino,agrego,modifico
			if(a[posa]==b[posb]) dp[posa][posb]=min(dp[posa][posb],solve(posa+1,posb+1));
		}
	}
	return dp[posa][posb];
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	forn(i,5002) forn(j,5002) dp[i][j]=-1;
	
	cin>>a>>b;
	if(sz(a)>sz(b)){
		string x = b;
		b=a;
		a=x;
	}
	
	int mini=INT_MAX;
	forn(i,sz(a)){
		mini=min(solve(i,0)+i,mini);
	}
	cout<<mini<<"\n";
	
	return 0;
}
