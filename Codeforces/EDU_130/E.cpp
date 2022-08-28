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
#define x first
#define y second

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct dist{
	int d,u,v;
};

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<ii> ptos(n);
	forn(N,n){
		cin >> ptos[N].x >> ptos[N].y;
	}
	
	vector<dist> dists;
	forn(u,n){
		forr(v,u+1,n){
			int d = abs(ptos[u].x-ptos[v].x) + abs(ptos[u].y-ptos[v].y);
			dists.pb({d,u,v});
		}
	}
	
	sort(dists.begin(), dists.end(), [](dist a, dist b){ return a.d<b.d; });
	
	
	
	return 0;
}




