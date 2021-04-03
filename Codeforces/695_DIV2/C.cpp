#include <bits/stdc++.h>
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
	// agregar g++ -DANARAP en compilacion
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n1,n2,n3;
	cin>>n1>>n2>>n3;
	vector<vector<ll>> arr;
	vector<ll> arr1(n1), arr2(n2), arr3(n3);
	forn(i,n1) cin>>arr1[i];
	forn(i,n2) cin>>arr2[i];
	forn(i,n3) cin>>arr3[i];
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	sort(arr3.begin(),arr3.end());
	arr.pb(arr1);
	arr.pb(arr2);
	arr.pb(arr3);
	ll sum1=0,sum2=0,sum3=0;
	forn(i,arr[0].size()) sum1+=arr[0][i];
	forn(i,arr[1].size()) sum2+=arr[1][i];
	forn(i,arr[2].size()) sum3+=arr[2][i];
	vector<pair<ll,ll>> ord;
	ord.pb({arr1[0],0});
	ord.pb({arr2[0],1});
	ord.pb({arr3[0],2});
	sort(ord.begin(),ord.end());
	ll mini=ord[0].snd, medi=ord[1].snd, maxi=ord[2].snd;
	
	ll sum=0;
	forr(i,0,arr[maxi].size()){
		sum+=arr[maxi][i];
	}
	forr(i,0,arr[medi].size()){
		sum+=arr[medi][i];
	}
	forr(i,0,arr[mini].size()){
		sum+=arr[mini][i];
	}
	ll ans=0;
	ans = max(sum-arr[maxi][0]*2-arr[medi][0]*2,ans);
	ans = max(sum-arr[maxi][0]*2-arr[mini][0]*2,ans);
	ans = max(sum-arr[medi][0]*2-arr[mini][0]*2,ans);
	ans = max(sum1+sum2-sum3,ans);
	ans = max(sum2+sum3-sum1,ans);
	ans = max(sum1+sum3-sum2,ans);
	
	cout<<ans<<"\n";
	
	
	
	
	return 0;
}
 
