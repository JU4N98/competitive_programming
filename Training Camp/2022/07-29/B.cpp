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
typedef pair<int,int> ii;

int n,m;
vector <vector <ii>> graph;
vector <int> val;
vector <int> used;\
int bit, compNow;
int cnt;
void dfs(int i){
	if(used[i]) return ;
	used[i] = 1;
	compNow++;
	for(auto e: graph[i]){
		if(not used[e.first]){
			int mask = e.second;
			int maskbit = (1<<bit) & mask;
			int mybit = (1<<bit) & val[i];
			
			if(not mybit and  maskbit) val[e.first] |= (1<<bit), cnt++; 
			if(mybit and not maskbit) val[e.first] |= (1<<bit), cnt++; 
			dfs(e.first);
		}
		
	}
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	graph.resize(n);
	forn(i,m){
			int a,b,c;
			cin>>a>>b>>c;
			a--;
			b--;
			graph[a].push_back({b,c});
			graph[b].push_back({a,c});
	}
	val.assign(n,0);

	long long sum = 0;
	forn(i,31){
			
			used.assign(n,0);
			bit = i;
			forn(x,n) {cnt=0,compNow=0; dfs(x);
			sum += ((long long)min(cnt,compNow-cnt)*(1LL<<bit));}
			
		
	}
	//~ for(auto e: val) cout<<e<<endl;
	bool ok =true;
	forn(i,n){
		for(auto e: graph[i]){
				if((val[i] ^ val[e.first]) != e.second) ok = false;
		}
	}
	if(ok)
	cout<<sum<<'\n';
	else cout<<-1<<'\n';
	return 0;
}





