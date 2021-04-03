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
	
	ll n, fact[21];
	fact[0]=1;
	forr(i,1,21){ 
		fact[i]=fact[i-1]*i;
	}
	cin>>n;
	ll ans =  (fact[n]/(fact[n/2]*fact[n/2]))/2*(fact[(n/2)-1])*(fact[(n/2)-1]);
	cout<<ans<<"\n";
	
	return 0;
}
