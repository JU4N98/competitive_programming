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
//#define ANARAP
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
	// agregar g++ -DANARAP en compilacion
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,x;
		cin>>n>>x;
		vector<ll> arr(n), cant(n,1);
		forn(i,n) cin>>arr[i];
		ll i=0;
		while(arr[i]%x==0){
			arr.pb(arr[i]/x);
			cant.pb(cant[i]*x);
			i++;
		}
		ll sum=0;
		forn(j,arr.size()){
			sum+=arr[j]*cant[j];
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}
