#include <bits/stdc++.h>
#define forr(i,a,b) for(ll i =(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i = n-1; i>=0; i--)
#define forall(it, v) for(auto it=v.begin(); it!=v.end(); it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
#define ANARAP

#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

double dp[1001][1001];
int n,x,y;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>x>>y;
	forn(i,n) forn(j,n) dp[i][j]=0.0;
	dp[0][n-x]=1.0;
	forn(i,n){
		forn(j,n){
			if(dp[i][j]!=0.0){
				
			}
		}
	}
	
	return 0;
}
 

