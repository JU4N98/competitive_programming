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
ll xx,yy,d;
void extEuclid(ll a,ll b){
	if(!b) {xx=1;yy=0;d=a;return;}
	extEuclid(b,a%b);
	ll x1=yy;
	ll y1=xx-(a/b)*yy;
	xx=x1;yy=y1;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	extEuclid(111,11);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		double ax=double(xx),ay=double(yy);
		//cout<< -ax*double(n)/11.0 <<" "<< ay*double(n)/111.0<<endl;
		if(ceil(-ax*double(n)/11.0) <= ay*double(n)/111.0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
	return 0;
}




