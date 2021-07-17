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

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		vector<ll> arr(n),suf(n+1);
		ll sum=0;
		forn(i,n){ cin>>arr[i]; sum+=arr[i];}
		if(sum<n){
			forn(i,n) arr[i]=0;
			forn(i,sum) arr[i]=1;
		}else{
			ll val=sum/n;
			forn(i,n) arr[i]=val;
			sum-=val*n;
			forn(i,sum) arr[i]++;
		}
		ll ans=0;
		dforn(i,n) suf[i]=suf[i+1]+arr[i];
		forn(i,n){
			ans+=abs(suf[i]-(n-i)*arr[i]);
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}




