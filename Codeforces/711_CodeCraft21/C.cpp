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
#define MOD 1000000007

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
		ll n,k;
		cin>>n>>k;
		vector<ll> planes(n+2);
		
		if(n==1){
			if(k>1) cout<<"2\n";
			else cout<<"1\n";
			continue;
		}
		
		forn(i,n) planes[i+1]=1;
		ll ans=0;
		for(int I=3;I<=k;I++){
			planes[n+1]=0;
			planes[0]=0;
			if(I%2==1){
				ll acum=0,aux;
				forr(i,1,n+1){
					 aux=planes[i];
					acum = (acum%MOD+planes[i]%MOD)%MOD;
					planes[i]=((acum-planes[i])%MOD+MOD)%MOD;
				}
			}else{
				ll acum=0;
				dforn(i,n+1){
					acum = (acum%MOD+planes[i]%MOD)%MOD;
					planes[i]=((acum-planes[i])%MOD+MOD)%MOD;
				}
			}
			planes[n+1]=0;
			planes[0]=0;
			//cout<<"I "<<I<<endl;
			//forr(i,1,n+1) cout<<planes[i]<<" ";
			//cout<<endl;
			forr(i,1,n+1) ans= (ans%MOD+planes[i]%MOD)%MOD;
			//cout<<ans<<endl;
		}
		ans++;
		if(k>=2) ans+=n;
		cout<<ans<<"\n";
	}
	
	return 0;
}



