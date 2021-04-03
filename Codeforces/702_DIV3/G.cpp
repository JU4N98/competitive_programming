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
		ll n,m;
		cin>>n>>m;
		vector<ll> a(n), prefix(n+1), x(m);
		forn(i,n) cin>>a[i];
		forn(i,m) cin>>x[i];
		forn(i,n) prefix[i+1] = a[i]+prefix[i];
		ll maxi = prefix[n];
		map<ll,ll> ma, ma2;
		forr(i,1,n+1){
			if(prefix[i]>=0 && ma.find(prefix[i])==ma.end()){
				ma[prefix[i]]=i-1;
				if(ma2.find(prefix[i])==ma2.end()) ma2[prefix[i]]=i-1;
			}else{
				if(maxi>0 && ma2.find(maxi-((prefix[i]%maxi)+maxi)%maxi)==ma2.end()){
					ma2[maxi-((prefix[i]%maxi)+maxi)%maxi]=i-1;
				}
			}
		}
		forn(i,m){
			if(ma.find(x[i])!=ma.end()) cout<<ma[x[i]]<<" ";
			else{
				if(maxi>0 && x[i]%maxi==0) cout<<ma2[x[i]%maxi]+(x[i]/maxi)*n-1<<" ";
				else if(maxi>0 && ma2.find(x[i]%maxi)!=ma2.end())  cout<<ma2[x[i]%maxi]+(x[i]/maxi)*n<<" ";
				else cout<<-1<<" ";
			} 
		}
		cout<<"\n";
	}
	
	return 0;
}




