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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin>>n;
	vector<ll> arr1,arr(n);
	ll sum=0;
	forn(i,n){ cin>>arr[i];sum+=arr[i];}
	ll ini=-1,med=sum/n,ans1=0,ans2=0;
	forn(i,n) if(arr[i]>med) ini=i;
	forn(i,n) arr[i]-=med;
	sum=0; arr1=arr;
	forn(i,n*2+1){
		ans1+=sum;
		ll aux=arr1[(i+ini)%n];
		arr1[(i+ini)%n]=min(0LL,arr1[(i+ini)%n]+sum);
		sum=max(0LL,aux+sum);
	}
	sum=0; arr1=arr;
	forn(i,n*2+1){
		ans2+=sum;
		ll aux=arr1[((ini-i)%n+n)%n];
		arr1[((ini-i)%n+n)%n]=min(0LL,arr1[((ini-i)%n+n)%n]+sum);
		sum=max(0LL,aux+sum);
	}
	cout<<min(ans1,ans2)<<"\n";
	
	return 0;
}




