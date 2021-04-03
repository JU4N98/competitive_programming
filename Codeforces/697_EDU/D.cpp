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
		ll ant, pres;
		cin>>pres;
		ll padres=1;
		ll hijos=0;
		ll ans=1;
		forn(j,n-1){
			ant=pres;
			cin>>pres;
			if(ant<pres){
				hijos++;
			}
			if(ant>pres){
				padres--;
				if(padres==0){
					ans++;
					padres=hijos;
					hijos=1;
				}else{
					hijos++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
