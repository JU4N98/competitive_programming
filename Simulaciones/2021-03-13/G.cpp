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
#define ANARAP

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

ll pares(ll n){
	return (n*(n-1))/2;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,m,k;
		cin>>n>>m>>k;
		set<ll> col, fil;
		vector<ll> vcol, vfil;
		forn(i,k){
			ll x,y;
			cin>>x>>y;
			vcol.pb(y-1);
			vfil.pb(x-1);
			col.insert(y-1);
			fil.insert(x-1);
		}
		ll cantcol = 0, cantfil=0;
		forn(i,m){
			if(col.lower_bound(i)==col.end()){
				cantcol+=(m-i);
			}else cantcol+= *(col.lower_bound(i))-i;
		}
		forn(i,n){
			if(fil.lower_bound(i)==fil.end()){
				cantfil+=(n-i);
			}else cantfil+= *(fil.lower_bound(i))-i;
		}
		ll ans=cantcol*cantfil;
		forn(i,k){
			ans+=pares(m-vcol[i]-1);
			ans+=pares(vcol[i]);
			ans+=pares(m-vfil[i]-1);
			ans+=pares(vfil[i]);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}



