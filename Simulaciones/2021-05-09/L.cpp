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
#define ANARAP

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
	
	
	ll n;
	cin>>n;
	map<string,double> cant;
	cant["pink"]=1.0;
	forn(i,n){
		string o,w;
		double ratio;
		cin>>o>>w>>ratio;
		cant[o]=max(cant[o],cant[w]+ratio);
	}
	cout<<min(cant["blue"],10.0)<<"\n";
	
	
	
	return 0;
}
 
 