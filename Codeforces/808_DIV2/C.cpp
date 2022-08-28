#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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
		int n, q; cin >> n >> q;
		vector<int> arr(n); forn(i,n) cin >> arr[i];
		
		int l = 0, r = n-1;
		while(l<r){
			int med = (l+r)/2;
			
			int curq = q;
			forr(i,med,n) if(curq < arr[i]) curq--;
			
			if(curq<0) l = med + 1;
			else r = med;
		}
		
		forn(i,l) cout << (arr[i]<=q ? '1' : '0');
		forr(i,l,n) cout << '1';
		cout << "\n";
	}
	
	return 0;
}




