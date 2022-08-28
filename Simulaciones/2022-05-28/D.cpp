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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t; cin >> t;
	forn(T,t){
		ll p,q; cin >> p >> q;
		
		ll pos = p*p - 4*q*q;
		if(pos<0){
			cout << "0 0\n";
			continue; 
		}
		
		ll aux = ll(floor(sqrt(pos)));
		ll root = -1;
		forr(i,max(aux-5LL,1LL),aux+6){
			if(i*i == pos) root = i;
		}
		
		if(root == -1){
			cout << "0 0\n";
			continue; 
		}
		
		ll a = p+root, b = 2*q, gcd = __gcd(a,b);
		cout << a/gcd << " " << b/gcd << "\n";
	}
	
	return 0;
}




