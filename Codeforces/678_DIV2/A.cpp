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
		ll n,m;
		cin>>n>>m;
		ll sum=0, in=0;
		forn(j,n){
			cin>>in;
			sum+=in;
		}
		if(sum==m) cout<<"YES\n"; else cout<<"NO\n";
	}
	return 0;
}
