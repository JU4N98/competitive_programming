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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,a,b;
	cin>>n>>a>>b;
	vector<ll> arr(n),prefix(n+1);
	forn(i,n) cin>>arr[i];
	forn(i,n) prefix[i+1]=prefix[i]+arr[i];
	
	multiset<ll> s;
	forr(i,a,b+1){
		s.insert(prefix[n-i]);
	}
	
	//~ forall(it,s) cout<<*it<<" ";
	//~ cout<<"\n";
	//~ forn(i,n+1) cout<<prefix[i]<<" ";
	//~ cout<<"\n";
	
	ll r=n-a,l=n-b,ans=LLONG_MIN;
	//~ cout<<l<<" "<<r<<endl;
	dforn(i,n+1){
		ll mini = *(s.begin());
		//~ cout<<*(s.begin())<<endl;
		ans=max(prefix[i]-mini,ans);
		s.erase(s.find(prefix[r]));
		r--;
		if(l-1>-1){
			l--;
			s.insert(prefix[l]);
		}
		if(sz(s)==0) break;
	}
	cout<<ans<<"\n";
	
	return 0;
}




