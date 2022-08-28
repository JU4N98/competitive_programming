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
	
	forr(i,1,17){
		int maxi = -1, ans = -1;
		forn(j,pow(2,i)){
			int mina = INT_MAX; int minb = INT_MAX;
			forn(k,i){
				forr(l,k+1,i){
					if(j&(1<<k) && j&(1<<l)){
						mina = min(mina,(k+1)^(l+1));
					}else if(!(j&(1<<k)) && !(j&(1<<l))){
						minb = min(minb,(k+1)^(l+1));
					}
				}
			}
			if(min(mina,minb)> maxi){
				maxi = min(mina,minb);
				ans = j;
			}
		}
		cout << "minxor:" << maxi << " config: " << ans << "\n";
		forn(j,i){
			cout << (ans&(1<<j) ? '1' : '2');
		}
		cout << "\n";
	}
	
	return 0;
}




