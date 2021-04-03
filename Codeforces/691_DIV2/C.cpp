#include<bits/stdc++.h>
using namespace std;

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
	
	
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n),b(m);
	forn(i,n) cin>>a[i];
	forn(i,m) cin>>b[i];
	
	sort(a.begin(),a.end());
	ll gcd = 0;
	forr(i,1,n) gcd = __gcd(a[i]-a[0],gcd);
	forn(i,m) cout<<__gcd(gcd,a[0]+b[i])<<" ";
	cout<<"\n";
	
	return 0;
}
