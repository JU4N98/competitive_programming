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
typedef pair<ll,ll> ii;

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
		ll n,m,x;
		cin>>n>>m>>x;
		set<ii> s;
		vector<ii> h(n);
		vector<ll>ans(n);
		
		forn(i,n){
			ll hi; cin>>hi;
			h[i]={hi,i};
		}
		sort(h.begin(),h.end());
		forn(i,m){
			s.insert({0,i});
		}
		forn(i,n){
			ii p = *(s.begin());
			s.erase(s.begin());
			ans[h[i].snd]=p.snd;
			s.insert({p.fst+h[i].fst,p.snd});
		}
		

		
		ii p1 = *(s.begin()),p2=*(s.rbegin());
		if(p2.fst-p1.fst<=x){
			cout<<"YES\n";
			forn(i,n){
				cout<<ans[i]+1<<" ";
			}
			cout<<"\n";
		}else cout<<"NO\n";
		
		
	}
	
	
	return 0;
}




