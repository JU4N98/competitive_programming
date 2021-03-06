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
	forn(T,t){
		ll n;
		cin>>n;
		vector<ll> arr(n);
		forn(i,n) cin>>arr[i];
		sort(arr.begin(),arr.end());
		if(arr[0]<0) cout<<"NO\n";
		else{
			cout<<"YES\n";
			multiset<ll> ms;
			forn(i,n) ms.insert(arr[i]);
			forr(i,0,arr[n-1]+1) if(ms.find(i)==ms.end()) ms.insert(i);
			cout<<ms.size()<<"\n";
			forall(it,ms) cout<<*it<<" ";
			cout<<"\n";
		}
	}
	
	
	return 0;
}




