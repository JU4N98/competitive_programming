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

bool solve(vector<ll> a, ll n, ll m){
	vector<ll> cols;
	
	ll sum = 0;
	forn(i,sz(a)){
		if(sum >= m) break;
		if(a[i]/n >= 2){
			cols.pb(a[i]/n);
			sum += a[i]/n;
		}
	}
	
	if(sum < m) return false;
	
	if(m-(sum-cols[sz(cols)-1])>=2) return true;
	else{
		if(sz(cols) == 1) return true;
		else{
			if(cols[0] > 2) return true;
			else return false;
		}
	}
}

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
		ll n,m,k; cin >> n >> m >> k; 
		vector<ll> a(k); forn(i,k) cin >> a[i];
		
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		
		if(solve(a,n,m) || solve(a,m,n)) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}




