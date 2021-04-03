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
//#define ANARAP

#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,a,b;
	double dp[1000005],da,db;
	cin>>n>>a>>b;
	da=double(a),db=double(b);
	forn(i,n+1) dp[i]=0.0;
	int l=0,r=0;
	double sum=0.0;
	bool a0 =false;
	if(a==0){ da=1.0; a++;a0=true;}
	
	forr(i,1,n+1){
		while(r<=i-a){
			sum+=dp[r];
			r++;
		}
		while(l<i-b){
			sum-=dp[l];
			l++;
		}
		if(a0) dp[i]=((db+1.0)/db)*(1.0+(sum/(db+1.0)));
		else dp[i]=(1.0+(sum/(db-da+1.0)));
	}
	cout<<fixed<<setprecision(5)<<dp[n]<<"\n";
	
	return 0;
}
 

