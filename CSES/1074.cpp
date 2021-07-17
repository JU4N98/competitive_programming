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
	
	ll n;
	cin>>n;
	vector<ll> arr(n);
	forn(i,n) cin>>arr[i];
	sort(arr.begin(),arr.end());
	if(sz(arr)%2==0){
		ll med1=arr[(n/2)-1],med2=arr[n/2],sum1=0,sum2=0;
		forn(i,n) sum1+=abs(arr[i]-med1),sum2+=abs(arr[i]-med2);
		cout<<min(sum1,sum2)<<"\n";
	}else{
		ll med = arr[n/2],sum=0;
		forn(i,n) sum+=abs(arr[i]-med);
		cout<<sum<<"\n";
	}
	
	return 0;
}




