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
	
	bool criba[1000000];
	forn(i,1000000) criba[i]=true;
	criba[0]=false;
	criba[1]=false;
	forr(i,2,1000000) if(criba[i]) for(int j=i*2;j<1000000;j+=i) criba[j]=false;
	vector<ll> primos;
	forr(i,2,1000000) if(criba[i]) primos.pb(i);
	 
	ll t;
	cin>>t;
	forn(T,t){
		ll z;
		cin>>z;
		ll ans=1;
		forr(i,1,primos.size()){
			if(primos[i-1]*primos[i]<=z) ans=primos[i-1]*primos[i];
		}
		cout<<"Case #"<<T+1<<": "<<ans<<"\n";
	}
	
	
	return 0;
}




