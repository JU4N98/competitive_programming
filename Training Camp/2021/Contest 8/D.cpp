#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(int  i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int  i=n-1;i>=0;i--)
#define foraint(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int )c.size())
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
typedef pair<int ,int > ii;
const int mod = 1000000007;

int  main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int  n,m; cin>>n>>m;
	multiset<ii> buses;
	forn(i,m){
		int  si,ti; cin>>si>>ti; buses.insert({si,ti});
	}
	multiset<ii> pq;
	
	pq.insert({0,0});
	int  formas = 1, parada=0,ans=0;
	while(!pq.empty()){
		parada = pq.begin()->fst;
		
		int actformas = formas;
		//quito los colectivos que terminan el recorrido en la parada actual
		while(pq.begin()!=pq.end() && pq.begin()->fst==parada){
			int dif = pq.begin()->snd; 
			if(parada!=0 && parada!=n){
				formas = ((formas+actformas-dif)%mod+mod)%mod;
			}
			if(parada==n){
				ans = ((ans+actformas-dif)%mod+mod)%mod;
			}
			pq.erase(pq.begin());
		}
		
		//agrego los colectivos que hacen un recorrido que contiene a la parada actual
		while(buses.begin()!=buses.end() && buses.begin()->fst<=parada){
			if(buses.begin()->snd>parada){
				if(parada!=0) pq.insert({buses.begin()->snd,actformas});
				else pq.insert({buses.begin()->snd,0});
			}
			buses.erase(buses.begin());
		}
		
	}
	
	if(parada!=n) cout<<"0\n";
	else cout<<((ans%mod)+mod)%mod<<"\n";
	
	return 0;
}




