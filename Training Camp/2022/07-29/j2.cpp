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
		int ans = 41;
		forn(bm,(1<<4)){
			vector<bool> s(4);
			vector<int> cost(4);
			vector<int> cost2(4);
			vector<int> cost3(4);
			forn(j,4){
				if((1<<j) & bm) s[j]=1;
				cost3[j] = calc(va[j], vb[j], s[j]);
			}
			forn(i,4){
				forn(j,4){
					cost[j] = calc(va[j], vb[j], s[j]);
					cost2[j] = calc(va[j], vb[j], s[j]);
				}
				for(int j = i; j<4; j++){
					bool ok = true;
					for(int k = i; k<j; k++){
							if(s[k] != s[k+1]){
								ok = false;
								break;
							}
					}
					if(ok){
						
						for(int k = i+1; k<=j; k++){
							if(cost[k-1] >= cost[k]) cost2[k] = 0;
							else cost2[k] = cost[k]-cost[k-1];
						}
							
						
					}
					forn(k,4) cost3[k] = min(cost3[k],cost2[k]);
				}
				
			}
			int aux =0;
				for(auto e: cost3) aux=+e;
				ans = min(ans,aux);
	
		}
		cout << ans << '\n';
	}
	
	return 0;
}





