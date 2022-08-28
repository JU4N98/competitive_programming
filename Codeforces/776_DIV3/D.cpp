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
		vector<int> ans;
		forn(i,n-1){
			vector<int> aux;
			forn(j,sz(arr)){
				if(arr[j] == sz(arr)){ 
					ans.pb((j+1)%(sz(arr)));
					forn(k,sz(arr)-1){
						aux.pb(arr[(j+k+1)%sz(arr)]);
						//cout << aux[k] << " ";
					}
					break;
				}
			}
			//cout << "\n";
			arr = aux;
		}
		ans.pb(0);
		reverse(ans.begin(),ans.end());
		forn(i,sz(ans)) cout << ans[i] << " ";
		cout << "\n";
	}
	
	return 0;
}




