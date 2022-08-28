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
#define r first.first
#define a1 first.second
#define a2 second
#define r1 first.first
#define r2 first.second
#define a second

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
	
	int t; cin >> t;
	forn(T,t){
		int n; cin >> n;
		vector<pair<ii,int>> as,ac,s,c; // straight and circular walls
		forn(i,n){
			char ty; cin >> ty; 
			if(ty == 'C'){
				int ra,aa1,aa2; cin >> ra >> aa1 >> aa2;
				ac.pb({{ra,min(aa1,aa2)},max(aa1,aa2)});
			}else{
				int ra1,ra2,aa; cin >> ra1 >> ra2 >> aa;
				as.pb({{ra1,ra2},aa});
			}
		}
		
		forn(i,360){
			set<ii> over;
			forn(j,sz(as)) if(as[i].a == i) over.insert(as[j].fst);
			while(!over.empty()){
				ii cur = *(over.begin());
				over.erase(cur);
				if(over.empty()){
					s.pb({cur,i});
					break;
				}
				ii nxt = *(over.begin());
				over.erase(nxt);
				if(cur.snd == nxt.fst){
					over.insert({cur.fst,nxt.snd});
				}else{
					s.pb({cur,i});
					over.insert(nxt);
				}
			}
		}
		
		forn(i,21){
			set<ii> over;
			forn(j,sz(ac)) if(ac[j].r == i) over.insert({ac[j].a1,ac[j].a2});
			while(!over.empty()){
				ii cur = *(over.begin());
				over.erase(cur);
				if(over.empty()){
					c.pb({cur,i});
					break;
				}
				ii nxt = *(over.begin());
				over.erase(nxt);
				if(cur.fst==nxt.snd && cur.snd==nxt.fst){
					over.insert({-1,-1});
				}else if(cur.fst==nxt.snd)
					over.insert({min(cur.snd,nxt.fst),max(cur.snd,nxt.fst)});
				else if(cur.snd==nxt.fst){
					over.insert({min(cur.fst,nxt.snd),max(cur.fst,nxt.snd)});
				}else{
					c.pb({{i,cur.fst},cur.snd});
					over.insert(nxt);
				}
			}
		}
		
		bool ans = true;
		sort(c.begin(),c.end()); // sort by radius
		forn(i,sz(c)-1){
			int ra1 = c[i].r, ra2 = c[i+1].r;
			
			vector<bool> wa(360);
			forn(j,sz(s)) if(s[j].r1<=ra1 &&  s[j].r2>=ra2){ //if the wall is between the circular walls, then there is a wall
				wa[s[j].a]=true;
			}	
			
			bool ok = false;
			while(!wa[c[i].a1]){ // from the lower angle of the inner circle, decrease it until there is a wall or a hole
				if(c[i].a1 == c[i+1].a1 || c[i].a1 == c[i+1].a2){
					ok = true;
					break;
				}
				c[i].a1 = ((c[i].a1-1)+360)%360;
			}
			
			while(!wa[c[i].a2]){ // from the upper angle of the inner circle, increase it until there is a wall or a hole
				if(c[i].a2 == c[i+1].a1 || c[i].a2 == c[i+1].a2){
					ok = true;
					break;
				}
				c[i].a2 = ((c[i].a2+1)+360)%360;
			}
			
			if(!ok) ans = false;
		}
		
		if(ans) cout << "YES\n"; else cout << "NO\n";
		
	}
	
	return 0;
}




