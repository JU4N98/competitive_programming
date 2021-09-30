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
typedef pair<ll,ll> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t; cin>>t;
	forn(T,t){
		ll d,n,k; cin>>d>>n>>k;
		multiset<pair<ll,ii>> act;
		multiset<ii> pq;
		multiset<ll> ans,oth;
		forn(i,n){
			ll h,b,e; cin>>h>>b>>e;
			act.insert({b,{e,-h}});
		}
		
		ll ti = act.begin()->fst,hp=0,acthp=0,tam=0;
		while(!act.empty()){
			
			if(!pq.empty() && pq.begin()->fst<act.begin()->fst) ti = pq.begin()->fst;
			else ti = act.begin()->fst;
			
			while(act.begin()->fst <= ti){
				ii p = act.begin()->snd;
				act.erase(act.begin());
				acthp-=p.snd;
				ans.insert(p.snd);
				tam++;
			}
			
			while(pq.begin()->fst < ti){
				ll val = pq.begin()->snd;
				if(oth.find(val)!=oth.end()){
					oth.erase(oth.find(val));
				}else{
					tam--;
					ans.erase(ans.find(val));
					acthp+=val;
				}
				pq.erase(pq.begin());
			}
			
			while(tam>k){
				acthp+=*prev(ans.end());
				oth.insert(*prev(ans.end()));
				ans.erase(prev(ans.end()));
				tam--;
			}
		}
		
		
		cout<<"Case #"<<T+1<<": "<<hp<<"\n";
	}
	
	return 0;
}




