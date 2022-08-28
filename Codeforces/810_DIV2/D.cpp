#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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
typedef pair<ll,ll> ii;

struct event{
	ll x, id, ty;
};

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	forn(T,t){
		ll n, m; cin >> n >> m;
		
		set<pair<ll,ii>> ev;
		vector<ll> p(n);
		forn(i,n){
			ll xi, pi; cin >> xi >> pi; p[i] = pi;
			ev.insert({xi-pi,{0LL,i}});
			ev.insert({xi,{1LL,i}});
			ev.insert({xi+pi,{2LL,i}});
		}
		
		set<ll> out;
		forn(i,n) out.insert(i);
		
		set<ii> up, down;
		
		vector<bool> ans(n,true);
		ll acum = 0, d=0, xi = ev.begin() -> fst;
		
		while(sz(ev)){
			pair<ll,ii> eva = *(ev.begin());
			ll xf = eva.fst;
			
			acum += (xf-xi)*d;
			
			if(acum>m){
				while(sz(out)){
					ans[*(out.begin())] = false;
					out.erase(out.begin());
				}
				while(sz(up) && acum-(xf - up.rbegin()->fst)>m){
					ans[up.rbegin()->snd] = false;
					up.erase(*(up.rbegin()));
				}
				while(sz(down) && acum-(down.begin()->fst-xf)>m){
					ans[down.begin()->snd] = false;
					down.erase(down.begin());
				}
			}
			
			while(sz(ev) && (*(ev.begin())).fst == xf){
				eva = *(ev.begin());
				ll x = eva.fst, ty = eva.snd.fst, id = eva.snd.snd; 
				ev.erase(ev.begin());
				
				switch(ty){
					case 0:
						out.erase(id);
						up.insert({x,id});
						d += 1;
					break;
					case 1:
						up.erase({x-p[id],id});
						down.insert({x+p[id],id});
						d -= 2;
					break;
					case 2:
						down.erase({x,id});
						out.insert(id);
						d += 1;
					break;
				}
			}
			
			xi = xf;
		}
		
		forn(i,sz(ans)) cout << ans[i];
		cout << "\n";
	}
	
	return 0;
}




