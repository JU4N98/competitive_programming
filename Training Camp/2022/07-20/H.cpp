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
const ll mod = 1000'000'007;

vector<int> kmp(string s){
	vector<int> pre(sz(s)); pre[0] = 0;
	
	forr(i,1,sz(s)){
		pre[i] = pre[i-1];
		
		while(pre[i]>0 && s[i]!=s[pre[i]])
			pre[i] = pre[pre[i]-1];
		
		if(s[i]==s[pre[i]]) pre[i]++;
	}
	
	return pre;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	string p; cin >> p;
	
	vector<int> pos(m);
	if(m>0) forn(i,m){
		cin >> pos[i];
		pos[i]--;
	}
	
	string s(n,'?');
	int last = 0;
	forn(i,m){
		int cur = max(0,last-pos[i]);
		int ini = max(last,pos[i]);
		
		forn(j,sz(p)-cur){
			s[ini+j] = p[cur+j];
			last++;
		}
	}
	
	vector<int> pre = kmp(p+"#"+s);
	
	//~ forn(i,sz(pre)) cout << pre[i] << " ";
	//~ cout << endl;
	
	bool ok = true;
	forn(i,sz(pos)){
		//~ cout <<sz(p)*2+pos[i] << endl;
		if(pre[sz(p)*2+pos[i]] != sz(p)) ok = false;
	}
	
	//~ cout << s << endl;
	
	ll ans = 1;
	if(!ok) ans = 0;
	forn(i,n) if(s[i] == '?') ans = (ans*26LL)%mod;
	cout << ans << "\n";
	
	return 0;
}
