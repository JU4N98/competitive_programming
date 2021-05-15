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
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		ll pos=-1;
		for(int i=0;i+1<n;i+=2){
			cout<<"? 1 "<<i+1<<" "<<i+2<<" "<<n-1<<endl;
			ll ans;
			cin>>ans;
			if(ans==n) pos=i+1;
			if(ans==n-1 && i>0){
				cout<<"? 1 "<<i<<" "<<i+1<<" "<<n-1<<endl;
				cin>>ans;
				if(ans==n) pos=i;
			}
			if(pos!=-1) break;
		}
		if(n%2==1){
			cout<<"? 1 "<<n-1<<" "<<n<<" "<<n-1<<endl;
			ll ans;
			cin>>ans;
			if(ans==n) pos=n-1;
		}
		if(pos==-1) pos=0;
		vector<ll> ans(n);
		ans[pos]=n;
		forn(i,n){
			if(i==pos) continue;
			cout<<"? "<<"2 "<<i+1<<" "<<pos+1<<" "<<1<<endl;
			cin>>ans[i];
		}
		cout<<"! ";
		forn(i,n) cout<<ans[i]<<" ";
		cout<<endl;
 	}
	
	return 0;
}




