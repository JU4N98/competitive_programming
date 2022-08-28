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
		int r,c; cin >> r >> c;
		vector<vector<char>> ans(r*2+1,vector<char>(c*2+1,'.'));
		forn(i,r*2+1){
			forn(j,c*2+1){
				if(i%2 == 0){
					if(j%2 == 0){
						ans[i][j] = '+';
					}else{
						ans[i][j] = '-';
					}
				}else{
					if(j%2 == 0){
						ans[i][j] = '|';
					}
				}
			}
		}
		ans[0][0] = ans[0][1] = ans[1][0] = '.';
		
		cout << "Case #" << T+1 << ":\n";
		forn(i,r*2+1){
			forn(j,c*2+1){
				cout << ans[i][j];
			}
			cout << "\n";
		}
	}
	
	return 0;
}




