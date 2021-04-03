#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b;a<c;a++)
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
		ll a, b;
		cin>>a>>b;
		ll ans=0;
		ll maxi=log2(max(a,b))+1;
		forn(j,maxi){
			if(!(a&(1<<j) && b&(1<<j)) && ((a&(1<<j) || (b&(1<<j))))) ans|=(1<<j);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
