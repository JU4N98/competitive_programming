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
	
	ll n,t;
	cin>>n>>t;
	forn(T,t){
		ll k;
		cin>>k;
		ll l=1,r=n;
		ll med=n;
		ll ans=0;
		while(med>=1){
			med/=2;
			cout<<"? "<<l<<" "<<r<<endl;
			ll sum;
			cin>>sum;
			ll cant=r-sum;
			if(cant>=k){
				r-=(med);
			}else{
				if(cant<k) r+=(med);
			}
		}
		cout<<"! "<<r+1<<endl;
	}
	
	return 0;
}




