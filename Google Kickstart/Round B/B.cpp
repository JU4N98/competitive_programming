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
		ll n;
		cin>>n;
		vector<ll> arr(n),dif1(n-1);
		vector<ii> dif;
		forn(i,n) cin>>arr[i];
		forr(i,1,n) dif1[i-1]=arr[i]-arr[i-1];
		forn(i,n-1){
			ll count=1;
			while(i+1<dif1.size() && dif1[i]==dif1[i+1]){count++;i++;}
			pair<ll,ll> p;
			p.fst=dif1[i]; p.snd=count;
			dif.pb(p);
		}
		ll ans=dif[0].snd;
		forn(i,dif.size()){
			if(i>0) ans=max(dif[i].snd+1,ans);
			if(i+1<dif.size()) ans=max(dif[i].snd+1,ans);
			if(i+2<dif.size()){
				if(dif[i+1].snd==1LL && (dif[i].fst+dif[i+1].fst)/2==dif[i+2].fst){
					ans=max(ans,dif[i+2].snd+2);
				}
				if(dif[i+1].snd==1LL && (dif[i+1].fst+dif[i+2].fst)/2==dif[i].fst){
					ans=max(ans,dif[i].snd+2);
				}
			}
			if(i+3<dif.size()){
				if(dif[i].fst==dif[i+3].fst && dif[i+1].snd==1LL && dif[i+2].snd==1LL && (dif[i+1].fst+dif[i+2].fst)/2==dif[i].fst){
					ans=max(ans,dif[i].snd+dif[i+3].snd+2);
				}
			}
		}
		if(n<=3) cout<<"Case #"<<T+1<<": "<<n<<"\n";
		else cout<<"Case #"<<T+1<<": "<<ans+1<<"\n";
		
		
		
	}
	
	return 0;
}




