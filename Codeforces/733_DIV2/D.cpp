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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef LASCALONETA
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
		set<ll> s;
		vector<ll> arr(n),cant(n);
		forn(i,n){ cin>>arr[i]; cant[arr[i]-1]++; };
		forn(i,n) s.insert(i+1);
		forn(i,n){
			if(s.find(arr[i])!=s.end()) s.erase(arr[i]);
		}
		ll ans=n;
		forn(i,n){
			if(cant[arr[i]-1]>1){
				if(s.upper_bound(i+1)!=s.end()){
					cant[arr[i]-1]--;
					arr[i]=*(s.upper_bound(i+1));
					s.erase(s.upper_bound(i+1));
					ans--;
				}else if(s.lower_bound(i+1)!=s.begin()){
					cant[arr[i]-1]--;
					arr[i]=*(prev(s.lower_bound(i+1)));
					s.erase(prev(s.lower_bound(i+1)));
					ans--;
				}
			}
		}
		cout<<ans<<"\n";
		forn(i,n) cout<<arr[i]<<" ";
		cout<<"\n";
		
	}
	
	
	return 0;
}



 
