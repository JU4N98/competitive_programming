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
#define MAXN 1000010

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

pair<int,int> sf[MAXN];
bool sacomp(int lhs, int rhs){ return sf[lhs]<sf[rhs];}

struct hash{
	vector<ll> pow, h;
	ll m = 1000'000'007;
	ll k = 31;
	
	void init(string &s){
		pow.resize(sz(s));
		h.resize(sz(s)+1);
		
		pow[0] = 1;
		forr(i,1,sz(s)) pow[i] = (pow[i-1] * k)%m;
		
		forn(i,sz(s)) h[i+1] = ((s[i] - 'a' + 1) * pow[i] + h[i]) % m;
	}
	
	ll getHash(ll l, ll r){
		return ((h[r+1]-h[l]+m)%m *pow[sz(pow)-l])%m;
	}
	
	bool comp(ll l1, ll r1, ll l2, ll r2){
		
		ll l = 0, r = maxi(r1-l1, r2-l2);
		
		while(l<r){
			ll med = (l+r+1)/2;
			
			if(getHash(l1,l1+med) == getHash(l2,l2+med)){
				l = med
			}else{
				r = med-1;
			}
		}
		
		if(l == maxi(r1-l1, r2-l2)){
			return r1-l1 < r2-l2;
		}else 
		
	}
	
};

vector<int> constructSA(string& s){
	int n = s.size();
	
	vector<int> sa(n), r(n);
	
	forn(i,n) r[i] = s[i];
	
	for(int m = 1; m<n; m*=2){
		forn(i,n){
			sa[i] = i, sf[i] = {r[i], i+m<n ? r[i+m] : -1};
		}
		
		stable_sort(sa.begin(), sa.end(), sacomp);
		
		r[sa[0]] = 0;
		
		forr(i,1,n) r[sa[i]] = sf[sa[i]] != sf[sa[i-1]] ? i : r[sa[i-1]];
	}
	return sa;
}
int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s; cin >> s;
	vector<int> sa = constructSA(s);
	
	forn(i,sz(sa)) cout << sa[i] << " ";
	cout << "\n";
	
	
	return 0;
}
