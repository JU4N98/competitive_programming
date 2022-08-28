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
	
	int n; cin >> n;
	vector<bool> let(26,false);
	vector<string> arr(n);
	forn(i,n){
		cin >> arr[i];
		let[arr[i][0]-'A'] = true;
	}
	bool ans = false;
	forn(i,n){
		bool ok = true;
		forn(j,sz(arr[i])) if(!let[arr[i][j]-'A']) ok = false;
		if(ok) ans = true;
	}
	if(ans) cout << "Y\n";
	else cout << "N\n";
	
	return 0;
}



