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
typedef pair<ll,ll> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n; cin>>n;
	
	vector<ii> arr(n);
	forn(i,n){
		ll qi,ci; cin>>qi>>ci;
		arr[i]={-qi,ci};
	}
	sort(arr.begin(),arr.end());
	
	ll m; cin>>m;
	vector<ll> b(m),ans(n); forn(i,m) cin>>b[i];
	
	vector<ll> menor(n);
	menor[0]=arr[0].snd;
	forr(i,1,n) menor[i]=min(menor[i-1],arr[i].snd);
	
	vector<ll> prefix(n+1); prefix[0]=0; forn(i,n) prefix[i+1]=prefix[i]+arr[i].snd;
	
	
	
		
	return 0;
}




