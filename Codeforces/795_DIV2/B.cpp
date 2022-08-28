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
		vector<int> arr(n); forn(i,n) cin >> arr[i];
		
		int count = 0; bool ok = true; vector<int> ans, curr;
		forn(i,n){
			if(count == 0 || (i!=0 && arr[i-1]==arr[i])){
				count++;
			}else{
				if(count == 1) ok = false;
				else{
					forn(j,sz(curr)) ans.pb(curr[(j+1)%sz(curr)]);
				}
				while(sz(curr)!=0) curr.pop_back();
				count = 1;
			}
			curr.pb(i);
		}
		if(count == 1) ok = false;
		else{
			forn(i,sz(curr)) ans.pb(curr[(i+1)%sz(curr)]);
		}
		
		if(!ok) cout << "-1\n";
		else{
			forn(i,sz(ans)) cout << ans[i]+1 << " ";
			cout << "\n";
		}
		
	}
	
	return 0;
}




