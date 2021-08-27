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
	
	int t; cin>>t;
	forn(T,t){
		int n; cin>>n;
		vector<int> arr(n); forn(i,n) cin>>arr[i];
		vector<int> ans(n+1);
		if(arr[n-1]==0){
			forn(i,n+1) ans[i]=i+1;
		}else if(arr[0]==1){
			ans[0]=n+1;
			forr(i,1,n+1) ans[i]=i;
		}else{
			forn(i,n-1){
				if(arr[i]==0 && arr[i+1]==1){
					forn(j,i+1) ans[j]=j+1;
					ans[i+1]=n+1;
					forr(j,i+2,n+1) ans[j]=j;
				}
			}
		}
		forn(i,n+1) cout<<ans[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}




