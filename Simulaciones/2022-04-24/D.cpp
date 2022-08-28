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
string u,v;
bool visi[210][210];
string mut[5] = {"AA", "BB", "CC", "ABAB", "BCBC"};

void dfs(int iu, int iv){
	if(visi[iu][iv]) return;
	//~ cout << iu << " " << iv << "\n";
	visi[iu][iv] = true;
	if(iu>=sz(u) && iv>=sz(v)) return;
	if(u[iu] == v[iv]) dfs(iu+1,iv+1);
	forn(i,5){
		bool match = true;
		forn(j,sz(mut[i])) if(iu+j>=sz(u) || u[iu+j] != mut[i][j]) match = false;
		if(match) dfs(iu+sz(mut[i]),iv); 
	}
	forn(i,5){
		bool match = true;
		forn(j,sz(mut[i])) if(iv+j>=sz(v) || v[iv+j] != mut[i][j]) match = false;
		if(match) dfs(iu,iv+sz(mut[i]));
	}
}

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
		cin >> u >> v;
		forn(i,210) forn(j,210) visi[i][j] = false;
		dfs(0,0);
		if(visi[sz(u)][sz(v)]) cout << "YES\n"; else cout << "NO\n";
	}
	
	
	return 0;
}




