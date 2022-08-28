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
typedef pair<int,int> ii;\

string solve(string aux){
	set<char> exist;
	vector<int> pos(20);
	dforn(i,sz(aux)){
		if(exist.count(aux[i])) continue;
		else{
			pos[aux[i]-'a']  = sz(exist);
			exist.insert(aux[i]);
		}
	}
	forn(i,sz(aux)) aux[i] = char(pos[aux[i]-'a']+'a');
	//~ cout << aux << '\n';
	return aux;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	string p; cin >> p;
	vector<string> ans;
	string aux = "";
	forn(i,n){
		aux += p[i];
		//~ cout << aux << '\n';
		ans.pb(solve(aux));
	}
	sort(ans.rbegin(), ans.rend());
	cout << *(ans.begin()) << '\n';

	return 0;
}





