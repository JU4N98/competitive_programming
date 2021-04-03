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
#define ANARAP

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
		ll n,d;
		cin>>n>>d;
		vector<ll> arr(n);
		forn(i,n) cin>>arr[i];
		sort(arr.begin(),arr.end());
		ll idx=-1
		forn(i,n) if(arr[i]<d) idx=i; else break;
		ll l=0, r=idx;
		bool sol=true;
		forr(i,idx+1,n){
			if(l<r){
				if(arr[l]+arr[r]>d) sol=false;
				else{
					l++;
					r--;
				}
			}else{
				sol = false;
			}
		}
		if(sol) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
	
	return 0;
}

