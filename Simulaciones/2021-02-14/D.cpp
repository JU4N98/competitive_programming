#include <bits/stdc++.h>
#define forr(i,a,b) for(long long i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.bend();it++)
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

#else

#endif

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main(){
	
	#ifdef ANARAP
	freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll N,M,R;
		cin>>N>>M>>R;
		R--;
		vector<ll> leaders(N);
		forn(i,N) cin>>leaders[i];
		vector<ii> relations(M);
		forn(i,M){
			ll a,b;
			cin>>a>>b;
			relations[i]={min(a-1,b-1),max(a-1,b-1)};
		}
		sort(relations.begin(),relations.end());
		vector<ll> control(N,1LL);
		leaders[0]--;
		control[R]=0;
		forn(i,M){
			ll f =relations[i].fst, s=relations[i].snd;
			if(control[s]==1){
				control[s]=0;
				leaders[f] = max(leaders[f]-1,0LL);
			}
		}
		
		
		ll pos=0;
		forn(i,N){
			if(i<R) pos = max(pos,i);
			else pos = max(pos,i+1);
			while(pos<N && leaders[i]>0){
				leaders[i]-= control[pos];
				pos++;
			}
		}
		
		ll ans=0;
		forn(i,N){
			ans+=leaders[i];
		}
		cout<<"Case #"<<T+1<<": "<<ans<<"\n";
	}
	
	return 0;
}




