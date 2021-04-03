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
		vector<bool> esta(n*2+2,false);
		forn(i,n) cin>>arr[i];
		ll ans=0;
		forn(i,n){
				if(!esta[arr[i]]){
					ans++;
					esta[arr[i]]=true;
				}else if (!esta[arr[i]+1]){
					esta[arr[i]+1]=true;
					ans++;
				}
		}
		cout<<ans<<"\n";
		arr.clear();
		esta.clear();
	}
	
	
	return 0;
}

