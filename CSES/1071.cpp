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
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll x,y;
		cin>>x>>y;
		ll ans=0;
		if(x>y){
			ans=(x-1)*(x-1);
			if(x%2==0){
				ans+=x;
				ans+=x-y;
			}else{
				ans+=y;
			}
		}else{
			ans=(y-1)*(y-1);
			if(y%2==0){
				ans+=x;
			}else{
				ans+=y;
				ans+=y-x;
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}




