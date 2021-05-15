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
const ll prim = 1000000007LL,prim2=1000000009LL;

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
		vector<pair<ii,ii>> ans;
		bool op=false;
		forr(i,1,n){
			if(__gcd(arr[i-1],arr[i])!=1LL){
				if(op){
					arr[i]=min(arr[i-1],arr[i]);
					arr[i-1]=prim;
					ans.pb({{i,i+1},{prim,arr[i]}});
				}else{
					arr[i]=min(arr[i-1],arr[i]);
					arr[i-1]=prim2;
					ans.pb({{i,i+1},{prim2,arr[i]}});
				}
				op=!op;
			}
		}
		cout<<sz(ans)<<"\n";
		forn(i,sz(ans)) cout<<ans[i].fst.fst<<" "<<ans[i].fst.snd<<" "<<ans[i].snd.fst<<" "<<ans[i].snd.snd<<"\n";
		
	}
	
	return 0;
}




