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
		ll n,m,in;
		cin>>n;
		vector<ll> red,blue;
		forn(i,n){ cin>>in; red.pb(in);}
		cin>>m;
		forn(i,m){cin>>in; blue.pb(in);}
		
		ll maxr=0, maxb = 0;
		
		forr(i,1,n) red[i]+=red[i-1]; 
		forr(i,1,m) blue[i]+=blue[i-1]; 
		forn(i,n) maxr=max(maxr,red[i]);
		forn(i,m) maxb=max(maxb,blue[i]);
		
		cout<<maxr+maxb<<"\n";
	}
	
	
	return 0;
}

