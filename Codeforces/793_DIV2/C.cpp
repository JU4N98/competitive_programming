// ANARAP+1 / La12
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
	
	int t; cin >> t;
	forn(T,t){
		int n; cin >> n;
		vector<int> arr(n); forn(i,n) cin >> arr[i];
		sort(arr.begin(),arr.end());
		
		vector<int> arra, arrb;
		int ans = 0; bool a = true; 
		forn(i,n){
			if(a){
				if(sz(arra)==0 || arra[sz(arra)-1]<arr[i]){
					arra.pb(arr[i]);
					a = false;
				}
			}else{
				if(sz(arrb)==0 || arrb[sz(arrb)-1]<arr[i]){
					arrb.pb(arr[i]);
					a = true;
					ans++;
				}
			}
		}
		
		bool add = false;
		if(sz(arrb) < sz(arra)){
			if(sz(arrb)==0) add = true; 
			else{
				forn(i,sz(arrb)){
					if(arrb[i]>arra[i] && (i-1==-1 || arra[i]>arrb[i-1])) add = true;
				}
				
				if(!a && arra[sz(arra)-1] > arrb[sz(arrb)-1]) add = true;
			}
		}
		ans += add;
		
		cout << ans << "\n";
	}
	
	return 0;
}




