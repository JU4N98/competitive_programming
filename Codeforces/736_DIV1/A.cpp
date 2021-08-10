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
typedef pair<int,int> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m; cin>>n>>m;
	vector<int> pos(n),neg(n);
	vector<vector<int>> g(n);
	forn(i,m){
		int u,v; cin>>u>>v; u--,v--;
		g[min(u,v)].pb(max(u,v));
		pos[max(u,v)]++;
		neg[min(u,v)]++;
	}
	
	int ans=n;
	queue<int> q;
	forn(i,n) if(pos[i]==0 && neg[i]>0){ q.push(i); ans--; }
	while(!q.empty()){
		int u = q.front();
		q.pop();
		forn(i,sz(g[u])){
			int v = g[u][i];
			pos[v]--;
			if(pos[v]==0 && neg[v]>0){q.push(v); ans--;}
		}
	}
	
	int qu; cin>>qu;
	forn(i,qu){
		int ope,u,v; cin>>ope;
		if(ope==1){
			cin>>u>>v; u--,v--;
			if(neg[min(u,v)]==0) ans--;
			neg[min(u,v)]++;
		}else if(ope==2){
			cin>>u>>v; u--,v--;
			neg[min(u,v)]--;
			if(neg[min(u,v)]==0) ans++;
		}else if(ope==3){
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}




