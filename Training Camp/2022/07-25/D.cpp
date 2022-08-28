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
const ll MOD = 1000'000'007;

void solve(vector<ll> &t0, vector<ll> &shift, ll m, ll n){
	vector<vector<ll>> adj0(m,vector<ll>(m));
	
	forn(i,m){
		forn(j,m){
			adj0[i][j] = shift[((-j+i)%m+m)%m];
			//~ cout << shift[((-j+i)%m+m)%m] << " ";
		}
		//~ cout << endl;
	}
	
	while(n>0){
		if(n&1){
			vector<ll> t1(m);
			forn(i,m)
				forn(j,m)
					t1[i] = (t1[i] + adj0[i][j]*t0[j])%MOD;
			t0 = t1;
		}
		
		
		vector<vector<ll>> adj1(m,vector<ll>(m));
		
		forn(i,m){
			forn(j,m){
				forn(k,m){
					adj1[i][j] = (adj1[i][j] + adj0[i][k] * adj0[k][j])%MOD;
					 
				}
			}
		}
		
		adj0 = adj1;
		
		n /= 2;
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
	
	ll n, l, m; cin >> n >> l >> m;
	
	vector<ll> ini(n), med(n), fin(n);
	forn(i,n) cin >> ini[i];
	forn(i,n) cin >> med[i];
	forn(i,n) cin >> fin[i];
	
	vector<ll> tot(m), shift(m);
	forn(i,n) tot[ini[i]%m]++;
	forn(i,n) shift[med[i]%m]++;
	
	solve(tot,shift,m,l-2);
	
	ll ans = 0;
	forn(i,n) ans = (ans + tot[((-fin[i]-med[i])%m+m)%m])%MOD;
	
	cout << ans << "\n"; 
	
	return 0;
}




