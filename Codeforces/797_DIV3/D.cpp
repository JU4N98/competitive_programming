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
		int n,k; cin >> n >> k;
		string s; cin >> s;
		vector<int> pref(n+1);
		forn(i,n) pref[i+1] = s[i] == 'B';
		forr(i,1,n+1) pref[i] += pref[i-1];
		
		//~ forn(i,n+1) cout << pref[i] << " ";
		//~ cout << endl;
		
		int ans = k;
		forn(i,n){
			//~ cout << i+1 << " "  << i+1-k << endl;
			if(i+1-k>-1) ans = min(ans, k - (pref[i+1]-pref[i+1-k]));
		}
		
		cout << ans << "\n";
		
	}
	
	return 0;
}




