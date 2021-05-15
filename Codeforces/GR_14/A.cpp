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
		ll n,x;
		cin>>n>>x;
		vector<ll> arr(n);
		forn(i,n) cin>>arr[i];
		ll sum=0;
		forn(i,n) sum+=arr[i];
		if(sum==x) cout<<"NO\n";
		else if(sum<x){
			cout<<"YES\n";
			forn(i,n) cout<<arr[i]<<" ";
			cout<<"\n";
		}else{
			sort(arr.begin(),arr.end());
			ll act=0,sk=-1;
			vector<ll> ans;
			forn(i,n){
				if(act+arr[i]==x) sk=i;
				else{
					ans.pb(arr[i]);
					act+=arr[i];
				}
			}
			ans.pb(arr[sk]);
			cout<<"YES\n";
			forn(i,n) cout<<ans[i]<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}




