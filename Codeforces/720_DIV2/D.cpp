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

ll calc(vector<int> &arr){
	ll ans=0;
	ll n=sz(arr);
	forn(i,n){
		if(arr[i]==0 || arr[i]==2) continue;
		ll ci=-1,cd=-1;
		dforn(j,i){
			if(arr[j]==0){
				ci=j;
				break;
			}
		}
		forr(j,i+1,n){
			if(arr[j]==0){
				cd=j;
				break;
			}
		}
		if(ci!=-1 && cd!=-1){
			if(i-ci<=cd-i){
				ans+=i-ci;
				arr[i]=2;
				arr[ci]=2;
			}else{
				ans+=cd-i;
				arr[i]=2;
				arr[cd]=2;
			}
		}else{
			if(ci==-1){
				ans+=cd-i;
				arr[i]=2;
				arr[cd]=2;
			}else{
				ans+=i-ci;
				arr[i]=2;
				arr[ci]=2;
			}
		}
	}
	return ans;
}


int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<int> arr(n),arr2(n);
	forn(i,n) cin>>arr[i];
	arr2=arr;
	reverse(arr2.begin(),arr2.end());
	cout<<min(calc(arr),calc(arr2))<<endl;
	
	return 0;
}




