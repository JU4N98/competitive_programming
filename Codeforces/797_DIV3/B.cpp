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
		int n; cin >> n;
		vector<int> a(n),b(n);
		forn(i,n) cin >> a[i];
		forn(i,n) cin >> b[i];
		
		bool ok = true;
		ll dif = b[0]-a[0];
		forn(i,n){
			if(b[i]-a[i]>0) ok = false;
			if(b[i]-a[i] < dif) dif = b[i] - a[i];
		}
		
		forn(i,n){
			if(max(a[i]+dif,0LL) != b[i]) ok = false;
		}
		
		if(ok) cout << "YES\n"; else cout << "NO\n";
	}
	
	
	return 0;
}




