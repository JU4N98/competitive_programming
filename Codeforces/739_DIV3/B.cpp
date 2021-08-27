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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t; cin>>t;
	forn(T,t){
		ll a,b,c; cin>>a>>b>>c;
		ll dist = max(a,b)-min(a,b);
		ll n = dist*2;
		
		if(a>n || b>n) cout<<"-1\n";
		else{
			if(c>n || (c+dist>n && c-dist<1)) cout<<"-1\n";
			else{
				if(c+dist<=n) cout<<c+dist<<"\n";
				else cout<<c-dist<<"\n";
			}
		}
		
	}
	
	return 0;
}




