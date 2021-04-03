#include <bits/stdc++.h>
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
	// agregar g++ -DANARAP en compilacion
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,m;
		cin>>n>>m;
		vector<ll> k(n), c(m);
		forn(i,n) cin>>k[i];
		forn(i,n) k[i]-=1;
		forn(i,m) cin>>c[i];
		sort(k.begin(),k.end());
		ll posk=n-1,posc=0,ans=0;
		while(posk>-1 && posc<m){
			//cout<<"+++++++++++"<<endl;
			//cout<<posc<<" "<<posk<<endl;
			//cout<<c[posc]<<" "<<c[k[posk]]<<endl;
			//cout<<"+++++++++++"<<endl;
			if(c[posc]<c[k[posk]]){
				ans+=c[posc];
				posc++;
				//cout<<c[posc]<<"\n";
			}else{
				ans+=c[k[posk]];
				//cout<<c[k[posk]]<<"\n";
			}
			posk--;
		}
		cout<<ans<<"\n";
		
	}
	
	return 0;
}
