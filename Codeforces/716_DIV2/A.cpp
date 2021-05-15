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
//#define ANARAP

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
	
	ll t;
	cin>>t;
	set<ll> s;
	forn(k,10001){
		s.insert(k*k);
	}
	forn(i,t){
		ll n;
		cin>>n;
		vector<ll> arr(n);
		forn(i,n) cin>>arr[i];
		bool sol=false;
		forn(i,n){
			if(s.find(arr[i])==s.end()) sol=true;
		}
		if(sol) cout<<"YES\n"; else cout<<"NO\n";
	}
	
	return 0;
}




