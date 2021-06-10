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
	
#else
	
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
	
	ll n,s,w;
	cin>>n>>s>>w;
	vector<ll> val(n),wei(n);
	ll sum=0;
	forn(i,n){
		cin>>val[i]>>wei[i];
		sum+=val[i];
	}
	ll lim=pow(2,n);
	ll maxi=LLONG_MIN,mini=LLONG_MAX;
	
	forn(i,lim){
		ll wi=0,vi=0;
		forn(j,n){
			
			if(i&(1<<j)){
				wi+=wei[j];
				vi+=val[j];
			}
			
		}
		//cout<<wi<<" "<<vi<<endl;
		if(wi==(w-s)){
				maxi=max(maxi,vi);
				mini=min(mini,vi);
		} 
	}
	if(maxi==LLONG_MIN) cout<<"-1\n";
	else cout<<sum-maxi<<" "<<sum-mini<<"\n";
	
	
	return 0;
}




