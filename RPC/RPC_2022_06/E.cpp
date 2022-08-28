#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(ll i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((ll)c.size())
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

struct roa{
	ll idx;
	ll m;
	ll w;
	ll dif;
};

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n, m; cin >> n >> m;
	vector<roa> roads;
	
	forn(i,m){
		ll idx, mi, w; cin >> idx >> mi >> w ; idx--;
		roads.pb({idx,mi,w,i});
	}
	sort(roads.begin(),roads.end(),[](roa a, roa b){return a.w<b.w || (a.w==b.w && a.dif<b.dif);});
	
	ll q; cin >> q;
	vector<ii> wei(q);
	forn(i,q){
		ll w; cin >> w;
		wei[i].fst = w;
		wei[i].snd = i;
	}
	sort(wei.begin(),wei.end());
	reverse(wei.begin(),wei.end());
	
	vector<ll> visi(n-1); ll count = n-1; ll sum = 0;
	vector<ll> ans(q,-1);
	
	forn(i,sz(wei)){
		while(!roads.empty() && roads[sz(roads)-1].w >= wei[i].fst){
			roa act = roads[sz(roads)-1];
			roads.pop_back();
			
			if(visi[act.idx]==0){
				count--;
				sum += act.m;
				visi[act.idx] = act.m;
			}else{
				if(act.m < visi[act.idx]){
					sum -= visi[act.idx];
					sum += act.m;
					visi[act.idx] = act.m;
				}
			}
		}
		
		if(count == 0) ans[wei[i].snd] = sum;
	}
	
	forn(i,q) 
		if(ans[i] != -1) cout << ans[i] << "\n";
		else cout << "impossible\n";
	
	return 0;
}




