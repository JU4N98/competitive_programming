#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it = v.begin(); it!=v.end(); it++)
#define fst first
#define snd second
#define pb push_back
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n,k;
		cin>>n>>k;
		vector<ll> arr(n*k);
		forn(j,n*k) cin>>arr[j];
		
		ll medi = (n+1)/2;
		ll ans=0;
		forr(j,k*(medi-1),n*k){
			ans+=arr[j];
			j+=(n-medi);
		}
		
		cout<<ans<<"\n";
		
		arr.clear();
	}
	
	
	return 0;
}
