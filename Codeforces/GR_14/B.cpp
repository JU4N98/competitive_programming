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
	
	set<ll> p2,p;
	ll aux=1,inc=3;
	while(aux*4<=1000000000){
		p2.insert(aux*4);
		aux+=inc;
		inc+=2;
	}
	aux=1;
	while(aux*aux<=1000000000){
		p.insert(aux*aux);
		aux++;
	}
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		cin>>n;
		if(p2.find(n)!=p2.end()) cout<<"YES\n";
		else if(n%2==0 && p.find(n/2)!=p.end()) cout<<"YES\n";
		else cout<<"NO\n"; 
	}
	return 0;
}




