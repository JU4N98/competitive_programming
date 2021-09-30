#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(ll i=n-1;i>=0;i--)
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

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	set<ll> s;
	ll i=1,lim=1000000000100;
	while(i*(3*i-1)/2<lim){
		s.insert(i*(3*i-1)/2);
		i++;
	}
	s.insert(i*(3*i-1)/2);
	
	ll t;cin>>t;
	forn(T,t){
		long double c; cin>>c;
		ll ce = ll(round(c));
		auto ite = s.upper_bound(ce);
		ll nex = *ite, pre = *prev(ite);
		long double pred = double(pre);
		long double nexd = double(nex);
		if(abs(pred-c)<=abs(nexd-c)) cout<<pre<<"\n";
		else cout<<nex<<"\n";
	}
	
	return 0;
}

