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
		int n,k; cin>>n>>k;
		vector<ii> arr(n);
		forn(i,n){
			cin>>arr[i].fst;
			arr[i].snd=i;
		}
		sort(arr.begin(),arr.end());
		
		int dif=0;
		forn(i,n-1){
			if(arr[i].snd+1!=arr[i+1].snd) dif++;
		}
		
		if(dif<=k-1) cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	
	return 0;
}




