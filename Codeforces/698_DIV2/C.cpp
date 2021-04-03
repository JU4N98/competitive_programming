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
		ll n;
		cin>>n;
		vector<ll> di(2*n), arr(n);
		forn(i,2*n) cin>>di[i];
		sort(di.begin(),di.end());
		bool sol=true;
		forn(i,n){
			if(di[2*i]!=di[2*i+1] || di[2*i]%2!=0 || di[2*i+1]%2!=0) sol=false;
			arr[i]=di[2*i];
		}
		
		vector<ll> dist;
		forr(i,1,n){
			ll aux = arr[i]-arr[i-1];
			if(aux%(2*i)!=0 || aux==0) sol=false;
			dist.pb(aux/(2*i));
		}
		forn(i,dist.size()){
			arr[n-1]-= dist[i]*2*n;
		}
		if(arr[n-1]/(2*n)<=0 || arr[n-1]%(2*n)!=0) sol=false;
		
		if(sol) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}


