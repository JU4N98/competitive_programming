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

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t; cin >> t;
	forn(T,t){
		ll n; cin >> n;
		string s; cin >> s;
		vector<ll> r(n); forn(i,n) cin>>r[i];
		forn(i,n) r[i]--;
		
		vector<bool> visi(n,false);
		ll ans = 1;
		forn(i,n){
			if(visi[i]) continue;
			
			ll act = i;
			vector<ll> cur;
			string ori;
			while(!visi[act]){
				visi[act] = true;
				ori.pb(s[act]);
				cur.pb(act);
				act = r[act];
			}
			
			forr(j,1,sz(cur)+1){
				bool ok = true;
				forn(k,sz(cur)) if(s[cur[k]] != ori[(k+j)%sz(ori)]) ok = false;
				if(ok){
					ans = (ans * j) / __gcd(ans,j);
					break;
				} 
			}
		}
		
		cout << ans <<"\n";
	}
	return 0;
}




