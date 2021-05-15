#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP

#ifdef ANARAP

#else

#endif 

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,b,r;
	cin>>n>>b>>r;
	vector<ii> ab(b),ar(r);
	forn(i,b) cin>>ab[i].fst>>ab[i].snd;
	forn(i,r) cin>>ar[i].fst>>ar[i].snd;
	
	vector<bool> vb(b),vr(r);
	vector<pair<ll,ii>> edges;
	
	
	
	
	return 0;
}
 
