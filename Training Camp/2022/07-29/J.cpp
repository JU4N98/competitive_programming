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

int calc(int a, int b, bool subo){
	if(subo){
		if(a <= b)return b-a;
		else return 10-a+b;
	}
	else{
		if(a>=b) return a-b;
		else return 10-b+a;
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
		string a, b; cin >> a >> b;
		vector<int> va(4), vb(4);
		forn(i,4) va[i] = a[i]-'0';
		forn(i,4) vb[i] = b[i]-'0';
		int ans = 100;
		forn(bm,(1<<4)){
			vector<bool> s(4);
			vector<int> cost(4), cost2(4);
			forn(j,4){
				if((1<<j) & bm) s[j]=1;
				cost[j] = calc(va[j], vb[j], s[j]);
			}
			forn(i,4) cost2[i] = cost[i];
			int pans = 0;
			forn(i,4){
				while(cost[i] > 0){
					pans++;
					int nxt = i;
					while(nxt < 4 && s[nxt] == s[i] && cost[nxt] > 0){
						cost[nxt]--;
						nxt++;
					}
				}
			}
			ans = min(pans, ans);
			//~ forn(i,4) cost[i] = cost2[i];
			//~ reverse(cost.begin(), cost.end());
			//~ pans=0;
			//~ forn(i,4){
				//~ while(cost[i] > 0){
					//~ pans++;
					//~ int nxt = i;
					//~ while(nxt < 4 && s[nxt] == s[i] && cost[nxt] > 0){
						//~ cost[nxt]--;
						//~ nxt++;
					//~ }
				//~ }
			//~ }
			//~ ans = min(pans, ans);
		}
		cout << ans << '\n';
	}
	
	return 0;
}





