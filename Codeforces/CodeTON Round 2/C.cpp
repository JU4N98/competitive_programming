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
typedef pair<int,int> ii;

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
		ll n, m; cin >> n >> m;
		
		vector<ll> inf(m); forn(i,m) cin >> inf[i];
		sort(inf.begin(),inf.end());
		
		vector<ll> alive;
		alive.pb(inf[0]-1+n-inf[m-1]);
		forn(i,m-1) alive.pb(inf[i+1]-inf[i]-1);
		
		sort(alive.begin(),alive.end());
		reverse(alive.begin(),alive.end());
		
		ll ans = 0, acum = 0;
		forn(i,sz(alive)){
			alive[i] -= acum;
			ans += alive[i] > 0;
			alive[i]-=2;
			ans += max(alive[i],0LL);
			acum += 4;
		}
		cout << n-ans << "\n";
	}
	
	return 0;
}




