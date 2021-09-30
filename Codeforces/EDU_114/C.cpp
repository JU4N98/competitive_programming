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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n; cin>>n;
	multiset<ll> he;
	ll sum = 0;
	forn(i,n){
		ll st; cin>>st; he.insert(st);
		sum+=st;
	}
	ll m; cin>>m;
	vector<ii> dr(m);
	forn(i,m) cin>>dr[i].fst>>dr[i].snd;
	forn(i,m){
		if(he.upper_bound(dr[i].fst)==he.end()){
			ll st = *prev(he.end());
			cout<< max(dr[i].fst-st,0LL) + max(dr[i].snd-sum+st,0LL)<<"\n";
		}else{
			ll ans = LLONG_MAX;
			if(he.upper_bound(dr[i].fst)!=he.begin()){
				ll st = *prev(he.upper_bound(dr[i].fst));
				ans = max(dr[i].fst-st,0LL) + max(dr[i].snd-sum+st,0LL);
			}
			ll st = *(he.upper_bound(dr[i].fst));
			ans = min(ans,max(dr[i].fst-st,0LL) + max(dr[i].snd-sum+st,0LL));
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}




