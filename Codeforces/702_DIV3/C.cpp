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
		ll x;
		cin>>x;
		bool ok=false;
		ll a=1;
		while(a*a*a<x && !ok){
			ll l=1,r=(ll) sqrt(x-a*a*a);
			ll med=(l+r)/2;
			while(l<r && !ok){
				med=(l+r)/2;
				if(l*l*l==x-a*a*a || r*r*r==x-a*a*a || med*med*med==x-a*a*a){
					ok=true;
				}else if(med*med*med<x-a*a*a){
					l=med+1;
				}else if(med*med*med>x-a*a*a){
					r=med;
				}
			}
			med=(l+r)/2;
			if(l*l*l==x-a*a*a || r*r*r==x-a*a*a || med*med*med==x-a*a*a) ok=true;
			a++;
		}
		if(ok) cout<<"YES\n"; else cout<<"NO\n";
	}
	
	
	return 0;
}




