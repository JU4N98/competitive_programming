#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b; a<c; a++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define ll long long
//#define ANARAP



int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		cin>>n;
		vector<ll> arr(n),ans;
		forn(j,n) cin>>arr[j];
		forn(j,(n/2)+1){
			ans.pb(arr[j]);
			if(!(n%2==1 && j==n/2)) ans.pb(arr[n-j-1]);

		}
		forn(j,n) cout<<ans[j]<<" ";
		cout<<"\n";
		ans.clear();
		arr.clear();
	}
	
	
	return 0;
}
