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
	
	int n, m, k; cin >> n >> m >> k;
	vector<ii> arr(n); 
	forn(i,n){
		cin >> arr[i].fst;
		arr[i].snd = i;
	}
	sort(arr.begin(),arr.end());
	
	int ans = 0;
	vector<int> aux;
	forn(i,n){
		int act = i;
		while(act<n && arr[act].fst == arr[i].fst){
			aux.pb(arr[act].snd);
			act++;
		}
		
		forn(j,sz(aux)){
			int l = j, r = sz(aux)-1;
			
			while(l<r){
				int med = (l+r+1)/2;
				int spent = aux[med]-aux[j] - (med-j);
				
				if(spent>k) r = med-1;
				else l = med;
			}
			
			ans = max(ans,l-j+1);
		}
		
		aux.clear();
		i = act-1;
	}
	
	cout << ans << "\n";
	
	return 0;
}




