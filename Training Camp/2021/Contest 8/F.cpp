#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
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

struct Hash {
	//P must be a prime number, could be randomly generated,
	//sometimes is good to make it close to alphabet size
	int P=1777771, MOD[2], PI[2];
	vector<int> h[2], pi[2];
	vector<ll> vp[2]; //Only used if getChanged is used (delete it if not)
	Hash(string& s) {
		//MOD[i] must be a prime of this order, could be randomly generated
		MOD[0]=999727999; MOD[1]=1070777777;
		//PI[i] = P^-1 % MOD[i]
		PI[0]=325255434; PI[1]=10018302;
		forn(k, 2)
			h[k].rsz(s.size()+1), pi[k].rsz(s.size()+1), vp[k].rsz(s.size()+1);
		forn(k, 2) {
			h[k][0] = 0; pi[k][0] = vp[k][0] = 1;
			ll p=1;
			forr(i, 1, s.size()+1) {
				h[k][i] = (h[k][i-1] + p*s[i-1]) % MOD[k];
				pi[k][i] = (1LL * pi[k][i-1] * PI[k]) % MOD[k];
				vp[k][i] = p = (p*P) % MOD[k];
			}
		}
	}
	ll get(int s, int e) { // get hash value of the substring [s, e)
		ll H[2];
		forn(i, 2) {
			H[i] = (h[i][e] - h[i][s] + MOD[i]) % MOD[i];
			H[i] = (1LL * H[i] * pi[i][s]) % MOD[i];
		}
		return (H[0]<<32)|H[1];
	}
	//get hash value of [s, e) if origVal in pos is changed to val
	//Assumes s <= pos < e. If multiple changes are needed, 
    //do what is done in the for loop for every change
    ll getChanged(int s, int e, int pos, int val, int origVal) {
        ll hv = get(s,e), h[2];
        h[1] = hv & ((1LL<<32)-1);
        h[0] = hv >> 32;
        forn(i, 2)
        	h[i] = (h[i] + vp[i][pos] * (val - origVal + MOD[i])) % MOD[i];
        return (h[0]<<32)|h[1];
    }
};

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,k; cin>>n>>k;
	string s; cin>>s;
	ll g; cin>>g;
	map<ll,ll> m;
	forn(i,g){
		string game; cin>>game;
		Hash hi = Hash(game);
		m[hi.get(0,k)]=i;
	}
	
	s+=s;
	Hash h = Hash(s);
	vector<ll> games(n*k);
	
	forn(i,n*k){
		ll hi = h.get(i,i+k);
		if(m.find(hi)!=m.end()) games[i]=m[hi];
		else games[i]=-1;
	}
	
	vector<bool> visi(n*k,false);
	vector<ll> ans;
	forn(i,n*k){
		if(visi[i]) continue;
		ll j = i;
		bool ok = true;
		set<ll> visi2;
		vector<ll> act;
		while(visi[j]==false){
			visi[j]=true;
			act.pb(games[j]);
			bool b1= games[j]!=-1LL;
			bool b2=visi2.find(games[j])==visi2.end();
			if(games[j]!=-1LL && visi2.find(games[j])==visi2.end()) visi2.insert(games[j]);
			else ok=false;
			j+=k;
			j = j%(n*k);
		}
		if(ok) ans=act;
	}
	if(sz(ans)==0) cout<<"NO\n";
	else{
		cout<<"YES\n";
		forn(i,n) cout<<ans[i]+1<<" ";
		cout<<"\n";
	}
	return 0;
}




