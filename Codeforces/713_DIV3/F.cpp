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
//#define ANARAP

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
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,c;
		cin>>n>>c;
		vector<ll> a(n),b(n-1);
		forn(i,n) cin>>a[i];
		forn(i,n-1) cin>>b[i];
		ll mini=(c+a[0]-1)/a[0];
		ll dias=0,ahorro=0;
		forr(i,0,n-1){
			if(ahorro<=b[i]){
				b[i]-=ahorro;
				ahorro=0;
			}else{
				ahorro-=b[i];
				b[i]=0;
			}
			dias+=(b[i]+a[i]-1)/a[i];
			ahorro+=((b[i]+a[i]-1)/a[i])*a[i]-b[i];
			mini=min(mini,dias+i+1+(c-ahorro+a[i+1]-1)/a[i+1]);
			//cout<<"dias "<<dias<<" ahorro "<<ahorro<<endl;
		}
		cout<<mini<<"\n";
	}
	
	return 0;
}




