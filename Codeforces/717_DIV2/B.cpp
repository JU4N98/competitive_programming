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
	
	int t;
	cin>>t;
	forn(T,t){
		int n;
		cin>>n;
		vector<int> arr(n), pref(n), suf(n);
		forn(i,n) cin>>arr[i];
		pref[0]=arr[0];
		forr(i,1,n) pref[i]=pref[i-1]^arr[i];
		suf[n-1]=arr[n-1];
		for(int i=n-2;i>-1;i--) suf[i]=suf[i+1]^arr[i];
		
		//forn(i,n) cout<<pref[i]<<" ";
		//cout<<endl;
		//forn(i,n) cout<<suf[i]<<" ";
		//cout<<endl;
		
		bool sol=false;
		forr(i,1,n-1){
			if(pref[i]==suf[i+1]) sol=true;
		}
		if(sol) cout<<"YES\n"; else cout<<"NO\n";
	}
	
	return 0;
}




