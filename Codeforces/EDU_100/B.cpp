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
	forn(i,t){
		ll n;
		cin>>n;
		vector<ll> arr(n), ans(n);
		forn(j,n) cin>>arr[j];
		ll sum=0, sum2=0;
		forn(j,n){
			ll loga = (long long) log2l(arr[j]);
			if(abs(arr[j]-pow(2,loga))<=abs(arr[j]-pow(2,loga+1)) || pow(2,loga+1)>1000000000){
				ans[j]=pow(2,loga);
			}else{
				ans[j]=pow(2,loga+1);
			}
			sum2 += abs(arr[j]-ans[j]);
			sum +=arr[j];
		}
		forn(j,n) cout<<ans[j]<<" ";
		cout<<"\n";
		arr.clear();
		ans.clear();
	}
	
	return 0;
}
