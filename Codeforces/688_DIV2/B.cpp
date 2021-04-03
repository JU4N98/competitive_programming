#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it = v.begin(); it!=v.end(); it++)
#define fst first
#define snd second
#define pb push_back
#define ll long long
#define ANARAP
vector<ll> arr, ord;
ll n;

ll calcular(ll median){
		ll ans=0;
		ll saltear;
		if(ord[n-1]-ord[median]>ord[median]-ord[0]){
			saltear=ord[n-1];
		}else{
			saltear=ord[0];
		}
		forn(j,n){
			if(arr[j]!=saltear) ans+=max(arr[j],arr[median])-min(arr[j],arr[median]);
		}
		return ans;
}

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		
		cin>>n;
		arr.resize(n);
		forn(j,n) cin>>arr[j];
		ord=arr;
		sort(ord.begin(),ord.end());
		
		if(n%2==0){
			cout<<min(calcular(n/2), calcular(n/2-1))<<"\n";
		}else{
			cout<<calcular(n/2)<<"\n";
		}
		
		ord.clear();
		arr.clear();
	}
	
	
	return 0;
}
