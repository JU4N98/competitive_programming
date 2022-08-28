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
		string s; cin >> s;
		vector<pair<char,int>> arr; arr.pb({s[0],1});
		forr(i,1,sz(s)){
			if(s[i] == arr[sz(arr)-1].fst) arr[sz(arr)-1].snd++;
			else arr.pb({s[i],1});
		}
		
		cout << "Case #" << T+1 << ": ";
		forn(i,sz(arr)-1){
			if(arr[i].fst<arr[i+1].fst){
				forn(j,arr[i].snd*2) cout << arr[i].fst;
			}else{
				forn(j,arr[i].snd) cout << arr[i].fst;
			}
		}
		forn(j,arr[sz(arr)-1].snd) cout << arr[sz(arr)-1].fst;
		cout << "\n";
	}
	
	return 0;
}
