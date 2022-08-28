#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	forn(T,t){
		ll n, k; cin >> n >> k;
		multiset<ii> ms;
		forn(i,n){
			ll w; cin >> w;
			ms.insert({w%k,w});
		}
		
		ll ans = 0;
		while(!ms.empty()){
			//~ forall(it,ms){
				//~ cout << "(" << it->fst << "," << it->snd <<")"<< " ";
			//~ }
			//~ cout << endl;
			ii min = *prev(ms.end());
			ms.erase(prev(ms.end()));
			//~ cout << min.fst << "," << min.snd << endl;
			auto par = ms.lower_bound({(k-min.fst)%k,0LL});
			if(par == ms.end()) par = ms.begin();
			ii parn = *par; 
			
			//~ cout << parn.fst << "," << parn.snd << endl;
			ms.erase(par);
			//~ cout << "OK" << endl;
			ans += (min.snd+parn.snd)/k;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}




