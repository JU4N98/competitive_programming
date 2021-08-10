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
typedef pair<int,int> ii;
const ll mod = 1000000007;
vector<ll> anum;
vector<ll> knum;
vector<ll> fact;
ll n,k,ans=0;

void solve(ll idx, ll sum, ll cant,string comb){
	if(idx==n) return;
	forn(i,2){
		if(i==0){
			solve(idx+1,sum,cant,comb);
		}else{
			bool ok = false;
			forn(j,k) if(sum+anum[idx]==knum[j]) ok=true;
			if(ok){
				//~ cout<<"combinacion "<<comb+" "+to_string(anum[idx])<<endl;
				ll mul =  ((fact[cant+1]%mod * fact[n-(cant+1)]%mod)%mod+mod)%mod;
				ans = ((ans%mod+mul)%mod+mod)%mod;
				//~ cout<<"cant elem "<<cant+1<<" ans "<<ans<<endl<<endl;
			}else solve(idx+1,sum+anum[idx],cant+1,comb+" "+to_string(anum[idx]));
		}
	}
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	fact.resize(27); fact[0]=1;  forr(i,1,27) fact[i] = (fact[i-1]%mod*i%mod)%mod;
	
	cin>>n;
	anum.resize(n); forn(i,n) cin>>anum[i];
	cin>>k;
	knum.resize(k);
	forn(i,k) cin>>knum[i];
	solve(0,0,0,"");
	ans = ((fact[n] - ans)%mod+mod)%mod;
	cout<<ans<<"\n";
	
	return 0;
}




