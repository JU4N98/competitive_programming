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
		vector<vector<int>> colour(4,vector<int>(3,0));
		forn(i,3){
			cin >> colour[0][i] >> colour[1][i] >> colour[2][i] >> colour[3][i];
		}
		int sum = 0;
		forn(i,4){
			sort(colour[i].begin(),colour[i].end());
			sum += colour[i][0];
		}
		cout << "Case #" << T+1 <<": ";
		if(sum<1000000) cout<<"IMPOSSIBLE\n";
		else{
			forn(i,4){
				cout << max(colour[i][0] - (sum-1000000),0) << " ";
				sum -= min((sum-1000000),colour[i][0]);
			}
			cout << "\n";
		}
	}
	
	return 0;
}




