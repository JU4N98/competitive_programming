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
	
	ll n, A, cf, cm, m; 
	cin >> n >> A >> cf >> cm >> m;
	vector<ii> skill(n);
	forn(i,n){
		cin >> skill[i].fst;
		skill[i].snd = i;
	}
	
	sort(skill.begin(),skill.end());
	vector<ll> pref(n+1);
	forn(i,n){
		pref[i+1] = skill[i].fst + pref[i];
	}
	
	reverse(skill.begin(),skill.end());
	vector<ll> suf(n+1);
	forn(i,n){
		suf[i+1] = skill[i].fst + suf[i];
	}
	
	reverse(skill.begin(),skill.end());
	
	ll ans = 0, mini = skill[0].fst, maxed = 0;
	forn(i,n+1){
		if(i*A - suf[i] > m) continue;
		if(i == n){
			ans = max(ans,i*cf + A*cm);
			mini = A;
			maxed = n;
			continue;
		}
		
		ll l = skill[0].fst, r = A;
		while(l<r){
			ll med = (l+r+1)/2;
			ii find = {med,LLONG_MAX};
			ll idx = min(ll(upper_bound(skill.begin(),skill.end(),find)-skill.begin()), ll(n-i));
			
			if(med*idx-pref[idx] <= m-(i*A-suf[i])) l = med;
			else r = med-1;
		}
		
		if(cf*i+l*cm > ans){
			ans = cf*i+l*cm;
			mini = l;
			maxed = i;
		}
	}
	
	forn(i,n) skill[i].fst = max(mini,skill[i].fst);
	forn(i,maxed) skill[n-i-1].fst = A;
	forn(i,n) swap(skill[i].fst,skill[i].snd);
	sort(skill.begin(),skill.end());
	
	cout << ans << "\n";
	forn(i,n) cout << skill[i].snd << " ";
	cout << "\n";
	
	
	return 0;
}
