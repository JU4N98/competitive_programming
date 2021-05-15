#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
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
	
	
		ll n;
		cin>>n;
		ll ans=1LL;
		vector<ll> sol;
		forr(i,1,n){
			if(__gcd(i,n)==1){
				sol.pb(i);
				ans=(ans*i)%n;
			}
		}
		if(ans%n==1){
			cout<<sol.size()<<"\n";
			forn(i,sol.size()) cout<<sol[i]<<" ";
			cout<<"\n";
		}else{
			cout<<sol.size()-1<<"\n";
			forn(i,sol.size()-1) cout<<sol[i]<<" ";
			cout<<"\n";
		}
	
	
	return 0;
}




