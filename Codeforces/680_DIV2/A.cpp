#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define pb(i) push_back(i)
#define fst first
#define snd second
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n,x;
		cin>>n>>x;
		vector<ll> a,b;
		a.resize(n);
		b.resize(n);
		forn(j,n) cin>>a[j];
		forn(j,n) cin>>b[j];
		sort(a.begin(),a.end());
		sort(b.begin(),b.end(),greater<ll>());
		bool sol = true;
		forn(j,n) if(a[j]+b[j]>x) sol=false;
		if(sol) cout<<"Yes\n"; else cout<<"No\n";
	}
	
} 
