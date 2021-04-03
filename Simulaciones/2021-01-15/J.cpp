#include <bits/stdc++.h>
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
ll dp[1010][1010];

ll solve(ll l, ll m){
	
	
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,k,m;
	cin>>n>>k>>m;
	forn(i,1010){
		forn(j,1010){
			dp[i][j]=-1;
		}
	}
	ll ans=0;
	m/=2;
	forr(i,1,min(k,m)+1){
		cout<<"SOLVE"<<endl;
		cout<<solve(i,m)*n<<endl;
		ans+=solve(i,m)*n;
	}
	cout<<ans<<endl;
	
	return 0;
}

