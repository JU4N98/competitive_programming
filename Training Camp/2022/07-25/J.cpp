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
	
	
	ll n; cin >> n;
	vector<ll> arr(n); forn(i,n) cin >> arr[i];
	
	vector<ll> pre(n+1), sum(n+1);
	
	forn(i,n) pre[i+1] = arr[i] + pre[i];
	
	forn(i,n) sum[i+1] = arr[i]*(i+1) + sum[i];
	
	ll l=n,r=n, ans = 0;
	while(l>0 && r>0){
		while(l>r) l--;
		
		while(l>0 && pre[r]-pre[l-1] >= 0){
			l--;
		}
		
		ll cur = (sum[r] - sum[l]) - (pre[r]-pre[l])*(l);
		ans = max(ans,cur);
		
		r--;
	}
	
	cout << ans << "\n";
	
	return 0;
}



 
