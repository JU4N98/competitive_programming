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

vector<pair<ii,ii>> comb(vector<ll> dim, int idx){
	vector<pair<ii,ii>> ans;
	
	forn(i,3){
		forr(j,i+1,3){
			forn(k,3){
				if(k!=i && k!=j){
					ans.pb({{min(dim[i],dim[j]),max(dim[i],dim[j])},{dim[k],idx}});
				}
			}
		}
	}
	
	return ans;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	
	vector<vector<ll>> stone(n,vector<ll>(3));
	multiset<pair<ii,ii>> ms;
	
	forn(i,n){
		forn(j,3){
			cin >> stone[i][j];
		}
		vector<pair<ii,ii>> combi = comb(stone[i],i);
		forn(j,sz(combi))
			ms.insert(combi[j]);
	}
	
	ll maxi = 0;
	ii ans = {-1, -1};
	forn(i,n){
		ll mini = stone[i][0];
		forn(j,3) mini = min(mini, stone[i][j]);
		if(mini > maxi){
			maxi = mini;
			ans = {i,i};
		}
		
		if(n == 1) continue;
		
		vector<pair<ii,ii>> combi = comb(stone[i],i);
		forn(j,sz(combi)) ms.erase(ms.find(combi[j]));
		forn(j,sz(combi)){
			auto ite = ms.upper_bound({combi[j].fst,{LLONG_MAX,LLONG_MAX}});
			ite = prev(ite);
			ii p = ite -> fst;
			ii p2 = ite -> snd;
			if(p.fst == combi[j].fst.fst && p.snd == combi[j].fst.snd){
				vector<ll> aux(3);
				aux[0] = p.fst;
				aux[1] = p.snd;
				aux[2] = combi[j].snd.fst + p2.fst;
				
				ll mini2 = aux[0];
				forn(k,3) mini2 = min(mini2,aux[k]);
				if(mini2 > maxi){
					maxi = mini2;
					ans = {i, p2.snd};
				}
			}
		}
		
		forn(j,sz(combi)) ms.insert(combi[j]);
	}
	
	if(ans.fst == ans.snd){
		cout << "1\n" << ans.fst+1 << "\n";
	}else{
		cout << "2\n" << ans.fst+1 << " " << ans.snd+1 << "\n";
	}
	
	
	return 0;
}




