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
#define ti first.first
#define ty first.second
#define h second.first
#define id second.second

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
	
	ll n, m; 
	cin >> n >> m;
	
	ll bounty, damage, increase;
	cin >> bounty >> increase >> damage;
	
	bool inf = false;
	multiset<pair<ii,ii>> ev;
	vector<ll> regen(n), maxi(n);
	forn(i,n){
		ll maxim, start, reg;
		cin >> maxim >> start >> reg;
		
		if((maxim <= damage || (reg==0 && start<=damage)) && increase>0) inf = true;
		regen[i] = reg;
		maxi[i] = maxim;
		
		if(start <= damage){
			ev.insert({{0,0},{start,i}});
		}
	}
	
	forn(i,m){
		ll tim, enemy, health;
		cin >> tim >> enemy >> health; enemy--;
		if(health <= damage){
			ev.insert({{tim,0},{health,enemy}});
		}else{
			ev.insert({{tim,1},{health,enemy}});
		}
	}
	
	if(inf){
		cout << "-1" << endl;
		return 0;
	}
	
	ll ans = 0;
	vector<pair<ii,ii>> out(n,{{-1,-1},{-1,-1}});
	set<ll> vict;
	
	while(sz(ev)){
		pair<ii,ii> eva = *(ev.begin());
		ll tact = eva.ti;
		
		ans = max(ans,((tact-1)*increase+bounty)*sz(vict));
		
		while(sz(ev) && eva.ti == tact){
			ev.erase(ev.begin());
			
			if(ev.find(out[eva.id]) != ev.end())
				ev.erase(ev.find(out[eva.id]));
			
			if(eva.ty == 0){
				vict.insert(eva.id);
				if(regen[eva.id] != 0){
					ev.insert({{(damage-eva.h)/regen[eva.id]+1+tact,1},{0,eva.id}});
					out[eva.id] = {{(damage-eva.h)/regen[eva.id]+1+tact,1},{0,eva.id}};
				}
			}else{
				if(vict.find(eva.id) != vict.end()) 
					vict.erase(eva.id);
			}
			
			if(sz(ev)) eva = *(ev.begin());
		}
		
		ans = max(ans,((tact-1)*increase+bounty)*sz(vict));
	}
	
	cout << ans << "\n";
	
	return 0;
}
