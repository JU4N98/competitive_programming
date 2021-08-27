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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t; cin>>t;
	forn(T,t){
		ll n; cin>>n;
		vector<vector<ll>> cav(n);
		forn(i,n){
			ll k; cin>>k;
			cav[i].resize(k);
			forn(j,k) cin>>cav[i][j];
		}
		
		multiset<ii> val;
		forn(i,n){
			ll ini = cav[i][0]+1;
			ll act = cav[i][0]+1;
			forn(j,sz(cav[i])){
				if(cav[i][j]>=act){
					ini += (cav[i][j] - act)+1;
					act = cav[i][j]+1;
				}
				act++;
			}
			val.insert({ini,(act-ini)});
		}
		ll ans=(val.begin())->fst;
		ll act=val.begin()->fst;
		forall(it,val){
			//~ cout<<it->fst<<" "<<it->snd<<endl;
			ii p = *it;
			if(act<p.fst){
				ans += p.fst-act;
				act = p.fst;
			}
			act += p.snd;
		}
		cout<<ans<<"\n";
		
	}
	
	return 0;
}




