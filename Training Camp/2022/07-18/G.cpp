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

ii dif(ii a, ii b){
	return {b.fst-a.fst, b.snd-a.snd};
}

ii sum(ii a, ii b){
	return {b.fst+a.fst, b.snd+a.snd};
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<ii> ptos(3);
	forn(i,3) cin >> ptos[i].fst >> ptos[i].snd;
	
	cout << "3\n";
	
	ii ans = sum(sum(dif(ptos[0],ptos[1]),dif(ptos[0],ptos[2])),ptos[0]);
	cout << ans.fst << " " << ans.snd << "\n";
	
	ans = sum(sum(dif(ptos[1],ptos[0]),dif(ptos[1],ptos[2])),ptos[1]);
	cout << ans.fst << " " << ans.snd << "\n";
	
	ans = sum(sum(dif(ptos[2],ptos[0]),dif(ptos[2],ptos[1])),ptos[2]);
	cout << ans.fst << " " << ans.snd << "\n";
	
	return 0;
}




