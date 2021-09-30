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

bool ok(vector<int> &arr, int lim){
	int mini=0,maxi=0,act=0;
	bool ans=true;
	forn(i,sz(arr)){
		if(max(act+arr[i],maxi)-mini<=maxi-min(act-arr[i],mini)){
			act+=arr[i];
			maxi=max(maxi,act);
		}else{
			act-=arr[i];
			mini=min(mini,act);
		}
		if(maxi-mini>lim) break;
	}
	if(maxi-mini>lim) ans=false;
	return ans;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;cin>>t;
	forn(T,t){
		int n; cin>>n;
		int l=0, r=0;
		vector<int> arr(n); forn(i,n){ cin>>arr[i]; r+=arr[i];}
		while(l<r){
			int med = (l+r)/2;
			if(ok(arr,med)){
				cout<<" ok "<<med<<"\n";
				r=med;
			}else{
				cout<<" nok "<<med<<"\n";
				l=med+1;
			}
		}
		cout<<l<<"\n";
	}
	
	return 0;
}




