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
	
	ll n;
	vector<ll> cuerd, nota;
	cuerd.resize(6);
	forn(i,6) cin>>cuerd[i];
	cin>>n;
	nota.resize(n);
	ll maxi=LLONG_MIN, mini=LLONG_MAX;
	forn(i,n){
		cin>>nota[i];
		if(nota[i]>maxi) maxi=nota[i];
		if(nota[i]<mini) mini=nota[i]; 
	}
	sort(cuerd.begin(),cuerd.end());
	sort(nota.begin(),nota.end());
	if(mini==maxi){
		cout<<0<<endl;
	}else{
		ll ans=LLONG_MIN;
		forn(k,n-1){
			ll auxi=LLONG_MAX;
			forn(i,6){
				forn(j,6){
					if(auxi>(nota[n-1]-cuerd[i])-(nota[k]-cuerd[j])) auxi=(nota[n-1]-cuerd[i])-(nota[k]-cuerd[j]);
				}
			}
			ans=max(ans,auxi);
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
