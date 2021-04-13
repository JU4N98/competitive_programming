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
	
	ll aux[9]={2,16,128,1024,16384,131072,1048576,16777216,134217728};
	ll t;
	cin>>t;
	forn(T,t){
		ll a,b,c;
		cin>>a>>b>>c;
		ll x=aux[c-1];
		ll y=aux[c-1];
		while(x<pow(10,a-1)) x*=2;
		while(y<pow(10,b-1)) y*=3;
		cout<<x<<" "<<y<<"\n";
	}
	
	
	return 0;
}




