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
string match = "WALDO";

bool sum(vector<vector<vector<int>>> &pref, int& rr, int& lr, int& rc, int& lc){
	bool ok = true;
	forn(i,5) if(pref[rr][rc][i] - pref[rr][lc-1][i] -pref[lr-1][rc][i] + pref[lr-1][lc-1][i] == 0) ok = false;
	return ok;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int h,w; cin >> h >> w;
	vector<vector<char>> mat(h,vector<char>(w));
	
	forn(H,h){
		forn(W,w){
			cin >> mat[H][W];
		}
	}
	
	if(w<h){
		vector<vector<char>> aux(w);
		dforn(r,h)
			forn(c,w)
				aux[c].pb(mat[r][c]);
		
		
		mat = aux;
		swap(h,w);
	}
	
	vector<vector<vector<int>>> pref(h+1,vector<vector<int>>(w+1, vector<int>(5)));
	forr(r,1,h+1){
		forr(c,1,w+1){
			forn(i,5){
				pref[r][c][i] = pref[r-1][c][i] + pref[r][c-1][i] - pref[r-1][c-1][i];
			}
			forn(i,5){
				if(match[i]==mat[r-1][c-1]) pref[r][c][i]++;
			}
			
		}
	}
	
	int ans = h*w +1;
	forr(lc,1,w+1){
		forr(lr,1,h+1){
			forr(rr,lr,h+1){
				int l = lc, r = w+1;
				
				bool ok = false;
				while(l<r){
					int med = (l+r)/2;
					bool ok2 = sum(pref,rr,lr,med,lc);
					
					ok |= ok2;
					if(ok2){
						r = med;
					}else{
						l = med + 1;
					}
				}
				
				
				if(!ok) continue;
				int rc = l;
				ans = min(ans, (rc - lc + 1) * (rr - lr +1));
			}
		}
	}
	
	if(ans>h*w) cout << "impossible\n";
	else cout << ans << "\n";
	
	return 0;
}
