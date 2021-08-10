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
vector<ll> h,t;
ll n,m;

bool ok(ll med){
	ll ult=0;
	forn(i,n){
		ll l = min(h[i],t[ult]);
		if(h[i]-l>med) continue;
		while(ult<m && t[ult]<=h[0]){ult++;}
		while(ult<m && min(h[i]-l,t[ult]-h[i])*2LL+max(h[i]-l,t[ult]-h[i])<=med) ult++;
		if(ult==m) return true;
	}
	return false;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n>>m;
	h.resize(n);t.resize(m);
	forn(i,n) cin>>h[i];
	forn(i,m) cin>>t[i];
	
	ll l,r;
	l=0,r=100000000000;
	while(l<r){
		ll med = (l+r)/2;
		if(ok(med)){
			r = med;
		}else{
			l = med+1;
		}
	}
	cout<<l<<endl;
	
	
	return 0;
}




