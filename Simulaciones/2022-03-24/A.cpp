// ANARAP 💙💛💙
// 💧🙌🏻
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

#ifdef ANARAP

#else

#endif


using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
	#ifdef ANARAP
	 freopen("input.in", "r", stdin);
	 #endif
	 
	int n; cin >> n;
	string a,b; cin >> a >> b;
	ll last = -1, ans = 0;
	forn(i,n){
		if(a[i]<b[i]){
			ans += (i-last)*(n-i);
			last = i;
		}
		if(a[i]>b[i]) last = i;
	}
	cout << ans << "\n";
	
	return 0;
}
