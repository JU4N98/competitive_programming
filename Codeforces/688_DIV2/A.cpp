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
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n,m;
		cin>>n>>m;
		vector<ll> a(n);
		set<ll> b;
		forn(j,n){
			cin>>a[j];
		}
		forn(j,m){
			ll aux;
			cin>>aux;
			b.insert(aux);
		}
		ll ans=0;
		forn(j,n){
			if(b.find(a[j])!=b.end()) ans++;
		}
		cout<<ans<<"\n";
		a.clear();
		b.clear();
	}
	
	
	
	return 0;
}
