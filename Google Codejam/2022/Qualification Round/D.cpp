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
typedef pair<ll,ll> ii;

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
		vector<ll> val(n+1), dad(n+1), deg(n+1), mini(n+1,LLONG_MAX);
		forn(i,n) cin >> val[i+1];
		forn(i,n){
			cin >> dad[i+1];
			deg[dad[i+1]]++;
		}
		dad[0]=-1;
		ll ans = 0;
		queue<ll> q; 
		forn(i,n) if(!deg[i+1]){
			 q.push(i+1);
			 mini[i+1] = val[i+1];
		}
		while(!q.empty()){
			ll act = q.front();
			q.pop();
			if(dad[act]==-1) break;
			if(mini[dad[act]]>mini[act]){
				if(mini[dad[act]]!=LLONG_MAX) ans += mini[dad[act]];
				mini[dad[act]] = mini[act];
			}else{
				ans += mini[act];
			}
			deg[dad[act]]--;
			if(deg[dad[act]]==0){
				mini[dad[act]] = max(mini[dad[act]],val[dad[act]]);
				q.push(dad[act]);
			}
		}
		ans += mini[0];
		cout << "Case #" << T+1 << ": " << ans << "\n";
	}
	
	return 0;
}




