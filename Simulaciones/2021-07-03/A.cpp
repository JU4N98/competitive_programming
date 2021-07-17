#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,n); for(ll i=0; i<n; i++)
#define forr(a,b,c); for(ll a=b; a<c; a++)
#define pb(i) push_back(i)

int main(){
	#ifdef REJUNTE
		freopen("input.in","r",stdin);
	#endif
	
	
	ll n, in, sum=0, mitad, cuenta=0;
	vector<ll> arr;
	cin>>n;
	ll x=0;
	forn(i,n){
		cin>>in;
		sum+=in;
		arr.pb(sum);
	}
	mitad=arr[n-1]/2;
	if(arr[n-1]%2==1){
		cout<<"N"<<endl;
	}else{
		forn(i,1e10) x++;
		int i=0;
		while(arr[i]<mitad+1){
			if(binary_search(arr.begin(), arr.end(),(arr[i]+mitad))) cuenta++;
			if(cuenta==2)break; 
			i++;
		}
		cuenta+=x;
		cuenta-=x;
		if(cuenta==2) cout<<"Y"<<endl; else cout<<"N"<<endl;
	}
	
	return 0;
}
