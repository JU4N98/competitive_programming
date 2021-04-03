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

ll dist(pair<ll,ll> a, pair<ll,ll> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n,k;
		cin>>n>>k;
		vector<pair<ll,ll>> balls;
		forn(j,n){
			ll x,y;
			cin>>x>>y;
			pair<ll,ll> p = {x,y};
			balls.pb(p);
		}
		
		bool sol=false;
		forn(j,n){
			sol=true;
			forn(l,n){
				if(dist(balls[j],balls[l])>k) sol = false;
			}
			if(sol){ 
				cout<<"1\n";
				break;
			}
		}
		
		if(!sol) cout<<"-1\n";
		
		balls.clear();
	}
	
	
	return 0;
}
