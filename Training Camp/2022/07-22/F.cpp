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

ll expMod(ll x, ll n, ll mod){
	ll ans = 1;
	
	while(n > 0){
		
		if(n&1) ans = (ans*x)%mod;
		
		x = (x*x) % mod;
		
		n/=2;
	}
	
	return ans;
}

struct LR{
	vector<ll> baseCase;
	vector<ll> recurrence;
	ll mod;
	
	void init(vector<ll> bc, vector<ll> r, ll m){
		baseCase = bc;
		recurrence = r;
		mod = m - 1;
	}
	
	ll solve(ll n){
		ll grade = sz(recurrence);
		
		vector<vector<ll>> pow(grade,vector<ll>(grade));
		forn(i,grade) pow[0][i] = recurrence[i];
		forr(i,1,grade) pow[i][i-1] = 1LL;
		
		vector<ll> x0(grade);
		forn(i,grade) x0[i] = baseCase[i];
		
		vector<vector<ll>> aux(grade,vector<ll>(grade));
		vector<vector<ll>> ans(grade,vector<ll>(grade)); forn(i,grade) ans[i][i] = 1LL;
		vector<ll> x1(grade);
		while(n>0){
			forn(i,grade) forn(j,grade) aux[i][j] = 0;
			if(n&1){
				forn(i,grade)
					forn(j,grade)
						forn(k,grade)
							aux[i][j] = (aux[i][j] + ans[i][k] * pow[k][j])%mod;
				ans = aux;
			}
			
			forn(i,grade) forn(j,grade) aux[i][j] = 0;
			forn(i,grade)
				forn(j,grade)
					forn(k,grade)
						aux[i][j] = (aux[i][j] + pow[i][k] * pow[k][j])%mod;
			pow = aux;
			
			n /= 2;
		}
		
		forn(i,grade)
			forn(j,grade)
				x1[i] = ((x1[i] + ans[i][j] * x0[j])%mod+mod)%mod;
		
		return x1[0];
	}	
};

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n, f1, f2, f3, c;
	cin >> n >> f1 >> f2 >> f3 >> c;
	
	switch(n){
		case 1:
			cout << f1 << "\n";
		break;
		case 2:
			cout << f2 << "\n";
		break;
		case 3:
			cout << f3 << "\n";
		break;
		default:
			LR lr;
			vector<ll> rec(3);
			vector<ll> bc(3);
			
			rec[0] = 1, rec[1] = 1, rec[2] = 1;
			bc[0] = 0, bc[1] = 0, bc[2] = 1;
			lr.init(bc,rec,MOD);
			ll ef1 = lr.solve(n-3);
			
			bc[0] = 0, bc[1] = 1, bc[2] = 0;
			lr.init(bc,rec,MOD);
			ll ef2 = lr.solve(n-3);
			
			bc[0] = 1, bc[1] = 0, bc[2] = 0;
			lr.init(bc,rec,MOD);
			ll ef3 = lr.solve(n-3);
			
			ll ec;
			if(n == 4){
				ec = 2;
			}else if(n == 5){
				ec = 6;
			}else{
				rec.resize(5);
				bc.resize(5);
				rec[0] = 3, rec[1] = -2, rec[2] = 0, rec[3] = -1, rec[4] = 1;
				bc[0] = 6, bc[1] = 2, bc[2] = 0, bc[3] = 0, bc[4] = 0;
				lr.init(bc,rec,MOD);
				ec = lr.solve(n-5);
			}
			
			ll ans = expMod(f1,ef1,MOD);
			ans = (ans * expMod(f2,ef2,MOD))%MOD;
			ans = (ans * expMod(f3,ef3,MOD))%MOD;
			ans = (ans * expMod(c,ec,MOD))%MOD;
			
			cout << ans << "\n";			
			
		break;
	}
	
	
	return 0;
}
