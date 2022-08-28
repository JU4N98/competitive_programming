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
		int n,m; cin >> n >> m;
		string a, b; cin >> a >> b;
		
		bool eq = true;
		forn(i,m-1){
			if(a[n-i-1] != b[m-i-1]) eq = false;
		}
		
		bool find = false;
		forr(i,m-1,n){
			if(a[n-i-1] == b[0]) find = true; 
		}
		
		if(find && eq) cout <<"YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




