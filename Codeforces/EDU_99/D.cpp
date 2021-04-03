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
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n), ord;
		forn(j,n) cin>>v[j];
		ord=v;
		ord.pb(x);
		sort(ord.begin(),ord.end());
		
		bool ordenado=true;
		
		forn(j,n-1) if(v[j]>v[j+1]) ordenado=false;
		
		if(!ordenado){
			bool sol=true;
			ll ans=0;
			forn(j,n){
				if(ord[j]!=v[j]){
					if(x==ord[j]){
						x=v[j];
						ans++;
					}else{
						sol=false;
						break;
					}
				}
			}
			
			if(sol) cout<<ans<<"\n"; else cout<<-1<<"\n";
		}else{
			cout<<0<<"\n";
		}
		
		
		ord.clear();
		v.clear();
	}
	
	
	return 0;
}
