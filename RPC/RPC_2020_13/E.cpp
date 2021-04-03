#include <bits/stdc++.h>
#define forr(i, a,b) for(int i=(a); i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP
#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

ll vidar (ll x, ll h){
	return x*h;
}

ll vidap(ll n, ll x, ll l){
	return (n-x)*l;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t,n,l,h;
	cin>>t;
	forn(i,t){
		cin>>n>>l>>h;
		ll x1 = (n*l)/(h+l), x2 = ((n*l)+(h+l-1))/(h+l);
		if(min(vidap(n,x1,l),vidar(x1,h))>min(vidap(n,x2,l),vidar(x2,h))){
			cout<<x1<<"\n";
		}else{
			cout<<x2<<"\n";
		}
	}
	
	
	
	return 0;
}
