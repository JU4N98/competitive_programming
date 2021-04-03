#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(ll a=b; a<c; a++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define ll long long
//#define ANARAP
ll fact[200005];

ll comb(ll n,ll k){
	if(n<k){
		return 0;
	}else{
		return fact[n]/(fact[k]*fact[n-k]);
	}
	
}

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	fact[0]=1;
	forr(j,1,200005) fact[j]=(fact[j-1]%1000000000000*j);
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		cin>>n;
		vector<ll> arr, num;
		arr.resize(n,0);
		num.resize(n+1,0);
		forn(j,n) cin>>arr[j];
		forn(j,n) num[arr[j]]++;
		ll ans=0;
		forr(j,1,n+1){
			ans+=comb(num[j],3);
			if((j+2)<(n+1)){
				ans+=comb(num[j],2)*(num[j+1]+num[j+2]);
				ans+=num[j]*comb(num[j+1]+num[j+2],2);
			}else if((j+1)<(n+1)){
				ans+=comb(num[j],2)*(num[j+1]);
				ans+=num[j]*comb(num[j+1],2);
			}
		}
		cout<<ans<<"\n";
		arr.clear();
		num.clear();
	}
	
	return 0;
}
