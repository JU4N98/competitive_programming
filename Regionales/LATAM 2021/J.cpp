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
ll h,w;

bool check(ii dot){
	return dot.x == 0LL || dot.x == w || dot.y == 0LL || dot.y == h; 
}

ll calc(ii dot){
	ll ans = 0LL;
	if(dot.y == 0LL){
		ans = dot.x + 1LL; 
	}else if(dot.y == h){
		ans = (w+1LL) + h + (w - dot.x);  
	}else{
		ans = dot.x == 0LL ? (w+1LL)*2LL + (h-1LL)*2LL - (dot.y-1LL): (w+1LL) + dot.y; 
	}
	return ans;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> w >> h;
	int n; cin >> n;
	pair<ii,ii> dots;
	vector<ii> arr;
	forn(i,n){
		cin >> dots.fst.x >> dots.fst.y;
		cin >> dots.snd.x >> dots.snd.y;
		if(check(dots.fst) && check(dots.snd)){
			ll m1 = calc(dots.fst), m2 = calc(dots.snd);
			arr.pb({min(m1,m2), max(m1,m2)});
		}
	}
	
	bool ok = true;
	if(sz(arr)>1){
		sort(arr.begin(),arr.end()); 		
		set<ll> s;
		s.insert(arr[0].fst);
		s.insert(arr[0].snd);
		forr(i,1,sz(arr)){
		    ll med = -1LL;
			if(s.ub(arr[i].fst) != s.end()) med = *(s.ub(arr[i].fst));
			if(med>arr[i].fst && med<arr[i].snd){
				ok = false;
				break;
			}
			s.insert(arr[i].fst);
			s.insert(arr[i].snd);
		}
	}
	if(ok) cout << "Y\n";
	else cout << "N\n";
	
	
	return 0;
}
