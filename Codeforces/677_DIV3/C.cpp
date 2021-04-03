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
		forn(j,n) cin>>in[j];
		vector<ll> aux = in;
		sort(aux.begin(),aux.end());
		ll maxi=aux[n-1];
		ll ans=-1;
		bool sol = false;
		forn(j,n){
			if(maxi==in[j]){
				if(j==0){
					if(in[1]!=in[0]){
						ans=0;
						sol=true;
					}
				}else if(j==n-1){
					if(in[n-1]!=in[n-2]){
						 ans=n-1;
						sol=true;
					}
				}else{
					if(in[j]!=in[j-1] || in[j]!=in[j+1]){
						 ans=j;
						sol=true;
					}
				}
			}
		}
		if(sol) cout<<ans+1<<endl;
		else cout<<-1<<endl;
		
	}
	
	
	return 0;
}
