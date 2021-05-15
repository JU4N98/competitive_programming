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
	vector<vector<ll>> pre(200010);
	
	forn(T,t){
		ll n;
		cin>>n;
		vector<ll> u(n);
		vector<ll> ans(n,0);

		
		forn(i,n){
			cin>>u[i];
			u[i]--;
		}
		forn(i,n){
			ll s;
			cin>>s;
			pre[u[i]].pb(s);
		}
		//~ forn(i,sz(pre)){
			//~ forn(j,sz(pre[i])){
				//~ cout<<pre[i][j]<<" "; 
			//~ }
			//~ if(!pre[i].empty())cout<<"\n";
		//~ }
		forn(i,n){
			if(sz(pre[i])>0){
				sort(pre[i].begin(),pre[i].end(),greater<ll>());
				forr(j,1,sz(pre[i])) pre[i][j]+=pre[i][j-1];
				forn(j,sz(pre[i])){
					ll tam=sz(pre[i])/(j+1);
					ans[j]+=pre[i][tam*(j+1)-1];
				}
			}
		}
		
		forn(i,n) cout<<ans[i]<<" ";
		cout<<"\n";
		forn(i,n) pre[i].clear();
		//cout<<endl; 
	}
	
	return 0;
}




