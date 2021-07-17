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
	
	int t;
	cin>>t;
	forn(T,t){
		int n;
		cin>>n;
		vector<int> arr(n);
		forn(i,n) cin>>arr[i];
		int ans=0;
		ans+=n;
		ans+=n-1;
		if(n>=3){
			ans+=n-2;
			forn(i,n-2){
				if((arr[i+1]>=arr[i] && arr[i+1]<=arr[i+2])
				|| (arr[i+1]<=arr[i] && arr[i+1]>=arr[i+2])) ans--;
			}
		}
		if(n>=4){
			ans+=n-3;
			forn(i,n-3){
				if((arr[i+1]>=arr[i] && arr[i+1]<=arr[i+2])
				|| (arr[i+1]<=arr[i] && arr[i+1]>=arr[i+2])
				|| (arr[i+2]>=arr[i+1] && arr[i+2]<=arr[i+3])
				|| (arr[i+2]<=arr[i+1] && arr[i+2]>=arr[i+3])
				|| (arr[i+1]>=arr[i] && arr[i+1]<=arr[i+3])
				|| (arr[i+1]<=arr[i] && arr[i+1]>=arr[i+3])
				|| (arr[i+2]>=arr[i] && arr[i+2]<=arr[i+3])
				|| (arr[i+2]<=arr[i] && arr[i+2]>=arr[i+3])) ans--;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}




