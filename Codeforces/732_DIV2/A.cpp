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
		vector<ll> a(n),b(n);
		ll suma=0,sumb=0;
		forn(i,n){ cin>>a[i]; suma+=a[i];}
		forn(i,n){ cin>>b[i]; sumb+=b[i];}
		if(suma!=sumb) cout<<"-1\n";
		else{
			vector<ll> dif(n);
			vector<ii> ans;
			forn(i,n) dif[i]=a[i]-b[i];
			ll i=0,j=0;
			while(i<n && j<n){
				while(i<n && dif[i]<=0) i++;
				while(j<n && dif[j]>=0) j++;
				while(dif[i]>0 && dif[j]<0){ ans.pb({i,j}); dif[i]--;dif[j]++;}
			}
			
			cout<<sz(ans)<<"\n";
			forn(i,sz(ans)) cout<<ans[i].fst+1<<" "<<ans[i].snd+1<<"\n";
		}
		
	}
	
	return 0;
}




