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
	
	ll n,q,k;
	cin>>n>>q>>k;
	vector<ll> arr(n+2),aux(n+2);
	forr(i,1,n+1) cin>>arr[i];
	arr[0]=1;
	arr[n+1]=k;
	
	forr(i,1,n+1){
		aux[i]=max(arr[i+1]-arr[i-1]-2,0LL);
	}
	
	//forn(i,n+2) cout<<arr[i]<<" ";
	//cout<<endl;
	//forn(i,n+2) cout<<aux[i]<<" ";
	//cout<<endl;
	forr(i,1,n+2) aux[i]+=aux[i-1];
	//forn(i,n+1) cout<<aux[i]<<" ";
	//cout<<endl;
	
	forn(i,q){
		ll li,ri;
		cin>>li>>ri;
		ll ans=0;
		ans+=arr[li+1]-2;
		ans+=k-arr[ri-1]-1;
		ans+=aux[ri-1]-aux[li];
		cout<<ans<<"\n";
	}
	
	return 0;
}



