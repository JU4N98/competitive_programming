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
		int n,m; cin >> n >> m;
		set<pair<ii,int>> s;
		forn(i,m){
			int x,w; cin >> x >> w;
			s.insert({{w,x},i});
		}
		set<ii> ord; int sum = 0;
		forn(i,2*n){
			pair<ii,int> act = *(s.begin());
			sum += act.fst.fst;
			ord.insert({act.fst.snd,act.snd});
			s.erase(s.begin());
		}
		cout << sum << "\n";
		forn(i,n){
			ii fs = *(ord.begin());
			ii ls = *(ord.rbegin());
			cout << fs.snd+1 << " " << ls.snd+1 << "\n";
			ord.erase(fs);
			ord.erase(ls);
		}
	}
	
	return 0;
}




