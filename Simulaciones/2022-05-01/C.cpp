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
typedef pair<ll,ll> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<ii> p(3);
	cin >> p[0].x >> p[0].y;
	cin >> p[1].x >> p[1].y;
	cin >> p[2].x >> p[2].y;
	
	ll top = LLONG_MIN, bot = LLONG_MAX; 
	sort(p.begin(),p.end());
	forn(i,3){
		top = max(p[i].y,top); 
		bot = min(p[i].y,bot);
	}
	
	cout << 3 << "\n";
	cout << p[1].x << " " << top << " " << p[1].x << " " << bot << "\n";
	cout << p[0].x << " " << p[0].y << " " << p[1].x << " " << p[0].y << "\n";
	cout << p[2].x << " " << p[2].y << " " << p[1].x << " " << p[2].y << "\n";
	
	return 0;
}




