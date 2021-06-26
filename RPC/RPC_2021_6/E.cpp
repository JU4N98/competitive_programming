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
#define ANARAP

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
	
	ll l,n;
	cin>>l>>n;
	vector<ll> right,left;
	ll mini=LLONG_MAX,max=LLONG_MIN;
	forn(i,n){
		ll a,b;
		cin>>a>>b;
		if(a<b) right.pb(b);
		if(a>b) left.pb(b);
		mini=min(mini,min(a,b));
		maxi=max(maxi,max(a,b));
	}
	sort(left.begin(),left.end());
	sort(right.begin(),right.end());
	ll ahorro=0;
	forn(i,sz(right)){
		if(i==sz(right)-1) ahorro=max(ahorro,maxi-right[i]);
	}
	
	return 0;
}




