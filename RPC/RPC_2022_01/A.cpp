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
	
	vector<int> t(n);
	
	int suf = 1;
	forn(i,n){
		cin >> t[i];
		suf *= t[i];
	}
	suf /= t[0];
	if(n>1) suf /= t[1];
	
	int ans = 0, pre = 1;
	forn(i,n-1){
		int act = t[i], nxt = t[i+1];
		
		int curr = 0;
		forn(acti,act){
			forn(nxti,nxt){
				if(nxti%10*10 + acti%10 >= act 
				|| nxti%10*10 + acti/10) curr ++;
			}
		}
		
		ans += ans;
		suf /= act;
		pre *= act;
	}
	
	return 0;
}




