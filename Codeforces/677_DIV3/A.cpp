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
		vector<ll> in;
		in.resize(n);
		
		ll unos=0, ceros=0, posuno=-1;
		forn(j,n){
			cin>>in[j];
			if(in[j]==0) ceros++; else{
				if(posuno==-1) posuno=j;
				unos++;
			}
		}
		
		ll ans=0;
		if(unos<=1){
			cout<<0<<endl;
		}else{
			ll ult=posuno;
			forr(j,posuno+1,n){
				if(in[j]==1){
					ans+=(j-ult-1);
					ult=j;
				}
			}
			cout<<ans<<endl;
		}
		
	}
	
	return 0;
}
