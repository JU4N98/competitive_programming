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
		vector<ii> arr(n);
		vector<ll> prefix(n+1);
		forn(i,n){
			ll aux;
			cin>>aux;
			arr[i]={aux,i};
		}
		sort(arr.begin(),arr.end());
		forr(i,1,n+1){
			prefix[i]+=arr[i-1].fst+prefix[i-1];
		}
		ll ans=0;
		vector<ll> vans;
		forr(i,0,n-1){
			if(prefix[i+1]>=arr[i+1].fst){
				ans++;
				vans.pb(arr[i].snd+1);
			}else{
				ans=0;
				vans.clear();
			}
		}
		ans++;
		vans.pb(arr[n-1].snd+1);
		sort(vans.begin(),vans.end());
		cout<<vans.size()<<"\n";
		forn(i,vans.size()){
			cout<<vans[i]<<" ";
		}
		cout<<"\n";
		
		
	}
	
	return 0;
}




