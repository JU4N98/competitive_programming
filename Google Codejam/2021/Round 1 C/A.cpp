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
		ll n,k;
		cin>>n>>k;
		vector<ll> tickets(n);
		forn(i,n) cin>>tickets[i];
		sort(tickets.begin(),tickets.end());
		vector<ll> largo,largo2;
		forn(i,n){
			if(i==0){
				largo.pb(tickets[i]-1LL);
				largo2.pb(tickets[i]-1LL);
			}
			if(i==n-1){
				largo.pb(k-tickets[i]);
				largo2.pb(k-tickets[i]);
			}
			if(i<n-1){
				if(tickets[i+1]==tickets[i]) continue;
				if((tickets[i+1]-tickets[i]-1)%2==0){
					largo.pb((tickets[i+1]-tickets[i]-1)/2);
					largo2.pb((tickets[i+1]-tickets[i]-1));
				}else{
					largo.pb(((tickets[i+1]-tickets[i]-1)/2) + 1LL);
					largo2.pb((tickets[i+1]-tickets[i]-1));
				}
			}
		}
		sort(largo.begin(),largo.end());
		sort(largo2.begin(),largo2.end());
		reverse(largo.begin(),largo.end());
		reverse(largo2.begin(),largo2.end());
		double ans=0;
		forn(i,min(2,sz(largo))) ans+=largo[i];
		ans/=double(k);
		if(sz(largo2)>0)ans=max(ans,largo2[0]/double(k));
		cout<<"Case #"<<T+1<<": ";
		cout<<fixed<<setprecision(7)<<ans<<"\n";
		
	}

	return 0;
}




