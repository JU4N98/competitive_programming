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
	
	int t; cin>>t;
	forn(T,t){
		ll n,a,b; cin>>n>>a>>b;
		if(n==1 || (n-1)%b==0){
			cout<<"Yes\n";
		}else{
			ll pot=1;
			bool ok=false;
			while(a!=1 && pot<=n && !ok){
				if((n-pot)%b==0) ok=true;
				pot*=a;
			}
			if(ok) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	
	return 0;
}




