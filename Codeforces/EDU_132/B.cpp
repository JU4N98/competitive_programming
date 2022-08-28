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
	
	int n, q; cin >> n >> q;
	vector<ll> h(n), pre(n), suf(n);
	forn(i,n) cin >> h[i];
	
	forn(i,n-1){
		pre[i+1] = max(h[i]-h[i+1],0LL);
		pre[i+1] += pre[i];
	}
	
	reverse(h.begin(),h.end());
	forn(i,n-1){
		suf[i+1] = max(h[i]-h[i+1],0LL);
		suf[i+1] += suf[i];
	}
	
	//~ forn(i,n) cout << pre[i] << " ";
	//~ cout << endl;
	//~ forn(i,n) cout << suf[i] << " ";
	//~ cout << endl;
	
	forn(Q,q){
		int s,t; cin >> s >> t; s--,t--;
		//~ cout << t-1 << " " << s-1 << endl;
		if(s<t) cout << pre[t]-pre[s] << "\n";
		else{
			s = (n-1)-s;
			t = (n-1)-t;
			cout << suf[t]-suf[s] << "\n";
		}
	}
	
	return 0;
}




