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

ii dif(ii p1, ii p2){
	return {p1.x-p2.x,p1.y-p2.y};
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<ii> pto(n), vec;
	forn(i,n) cin >> pto[i].fst >> pto[i].snd;
	
	forn(i,n)
		forr(j,i+1,n)
			vec.pb(dif(pto[j],pto[i]));
			
	forn(i,sz(vec))
		if(vec[i].x < 0 || (vec[i].x==0 && vec[i].y<0))  vec[i] = {-vec[i].x,-vec[i].y};
		
	sort(vec.begin(),vec.end());
	
	ll ans = 0, count = -1;
	forn(i,sz(vec)){
		if(count == -1) count = 1;
		else if(vec[i] == vec[i-1]){
			count++;
		}else{
			ans += (count * (count-1)) / 2;
			count = 1;
		}
	}
	ans += (count * (count-1)) / 2;
	
	cout << ans/2 << "\n";
	
	return 0;
}




