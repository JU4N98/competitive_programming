#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound 
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP
#ifdef ANARAP
#else
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,m,a,b;
		cin>>n>>m>>a>>b;
		multiset<ll> fire;
		forn(i,m){
			ll in;
			cin>>in;
			fire.insert(in);
		}
		if(a<b){
			ll cantMax=b-a-1,tiempoMax=b-1;
			ll ans=0;
			auto it = fire.upper_bound(tiempoMax);
			if(it!=fire.begin())it = prev(it);
			while(it!=fire.begin() && cantMax!=0 && tiempoMax!=0){
				if(*it<tiempoMax){
					ans++;
					cantMax--;
					tiempoMax--;
				}
				it = prev(it);
			}
			if(cantMax!=0 && tiempoMax!=0 && *it<tiempoMax) ans++;
			cout<<ans<<"\n";
		}else{
			ll cantMax=a-b-1,tiempoMax=n-b;
			ll ans=0;
			auto it = fire.upper_bound(tiempoMax);
			if(it!=fire.begin()) it = prev(it);
			while(it!=fire.begin() && cantMax!=0 && tiempoMax!=0){
				if(*it<tiempoMax){
					ans++;
					cantMax--;
					tiempoMax--;
				}
				it = prev(it);
			}
			if(cantMax!=0 && tiempoMax!=0 && *it<tiempoMax) ans++;
			cout<<ans<<"\n";
		}
		fire.clear();
		
	}
	
	
	return 0;
}


