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
typedef pair<int,int> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,k; cin>>n>>k;
	vector<ll> arr(n); forn(i,n) cin>>arr[i];
	sort(arr.begin(),arr.end());
	ll cost=0,l=0,ans=1,ansi=arr[0];
	forr(i,1,n){
		cost += (i-l) * (arr[i]-arr[i-1]);
		//~ cout<<"arri "<<arr[i]<<" cost "<<cost<<" ansi "<<(i-l)+1<<"\n";;
		if(cost>k){
			while(l<n && cost>k){ cost-= (arr[i]-arr[l]); l++;}
		}
		if(ans<(i-l)+1){
			ans = (i-l)+1;
			ansi = arr[i];
		}
	}
	cout<<ans<<" "<<ansi<<"\n";
	
	return 0;
}




