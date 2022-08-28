#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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
	
	ll n, p; cin >> n >> p;
	set<pair<ii,ll>> event;
	vector<ll> ans(n);
	forn(i,n){
		ll ti; cin >> ti;
		event.insert({{ti,1},i});
	}
	
	queue<ll> q; set<ll> wait; set<ll> seat;
	ll t = 0; bool disp = true; wait.insert(1000000);
	while(sz(event)){
		pair<ii,ll> e = *(event.begin());
		t = e.fst.fst;
		
		if(e.fst.snd == 0){
			disp = true;
			q.pop();
			wait.erase(e.snd);
			ans[e.snd] = t;
			event.erase(event.begin());
		}
		
		e = *(event.begin());
		while(sz(event) && e.fst.fst <= t){
			seat.insert(e.snd);
			event.erase(event.begin());
			if(sz(event)) e = *(event.begin());
		}
		
		if(sz(seat) && *(seat.begin()) < *(wait.begin())){
			wait.insert(*(seat.begin()));
			q.push(*seat.begin());
			seat.erase(seat.begin());
		}
		
		if(disp && sz(wait)>1){
			ll w = q.front();
			event.insert({{t+p,0},w});
			disp = false;
		}
	}
	
	forn(i,n) cout << ans[i] << " ";
	cout << "\n";
	
	return 0;
}




