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
		vector<ll>arr(n),mini,maxi(n,-1);
		vector<bool> minib(n,true),maxib(n,true);
		forn(i,n) cin>>arr[i];
		mini.pb(arr[0]);
		maxi[0] = arr[0];
		minib[arr[0]-1]=false;
		maxib[arr[0]-1]=false;
		ll ultmini=1;
		forr(i,1,n){
			if(arr[i-1]==arr[i]){
				while(!minib[ultmini-1]) ultmini++;
				minib[ultmini-1]=false;
				mini.pb(ultmini);
			}else{
				maxib[arr[i]-1]=false;
				maxi[i]=arr[i];
				minib[arr[i]-1]=false;
				mini.pb(arr[i]);
			}
		}
		set<ll> s;
		forn(i,n) if(maxib[i]) s.insert(i+1);
		forn(i,n){
			if(maxi[i]==-1){
				if(s.size()!=1){
					auto ite = prev(s.lower_bound(arr[i]));
					maxi[i] = *ite;
					s.erase(*ite);
				}else{
					maxi[i]=*s.begin();
				}
			}
		}
		forn(i,n) cout<<mini[i]<<" ";
		cout<<"\n";
		forn(i,n) cout<<maxi[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}




