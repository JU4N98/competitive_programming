#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b; a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define snd second
#define fst first
#define pb push_back
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		vector<ll> arr(n);
		forn(i,n) cin>>arr[i];
		set<ll> ans;
		
		forn(i,n)
			forn(j,n)
				if(arr[i]-arr[n-1-j]!=0) ans.insert(abs(arr[i]-arr[n-j-1]));
				
		cout<<ans.size()<<endl;
		arr.clear();
		ans.clear();
	}
	
	return 0;
}
