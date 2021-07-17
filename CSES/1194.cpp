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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
int n,m;

char mov(int p, int h){
	ii pp = {p/m,p%m}, ph = {h/m,h%m};
	ii ans = {ph.fst-pp.fst,ph.snd-pp.snd};
	if(ans.fst==1) return 'D';
	if(ans.fst==-1) return 'U';
	if(ans.snd==1) return 'R';
	if(ans.snd==-1) return 'L';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n>>m;
	vector<string> mat(n);
	forn(i,n) cin>>mat[i];
	vector<vector<int>> g(n*m);
	int ax[4]={0,0,1,-1},ay[4]={1,-1,0,0};
	forn(i,n){
		forn(j,m){
			if(mat[i][j]=='#') continue;
			forn(k,4){
				int xi=i+ax[k],yi=j+ay[k];
				if(xi>=0 && xi<n && yi>=0 && yi<m && mat[xi][yi]!='#') g[i*m+j].pb(xi*m+yi); 
			}
		}
	}
	
	vector<int> distm(n*m,-1),dista(n*m,-1),dad(n*m,-1);
	queue<int> q;
	forn(i,n) forn(j,m) if(mat[i][j]=='M'){ q.push(i*m+j);distm[i*m+j]=0;}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		forn(i,sz(g[u])){
			int v = g[u][i];
			if(distm[v]==-1){
				distm[v]=distm[u]+1;
				q.push(v);
			}
		}
	}
	
	forn(i,n) forn(j,m) if(mat[i][j]=='A'){ q.push(i*m+j);dista[i*m+j]=0;}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		forn(i,sz(g[u])){
			int v = g[u][i];
			if(dista[v]==-1){
				if(distm[v]==-1 || distm[v]>dista[u]+1){
					q.push(v);
					dista[v]=dista[u]+1;
					dad[v]=u;
				}
			}
		}
	}
	//~ forn(i,n){
		//~ forn(j,m) cout<<distm[i*m+j]<<" ";
		//~ cout<<"\n";
	//~ }
	//~ cout<<"\n";
	//~ forn(i,n){
		//~ forn(j,m) cout<<dista[i*m+j]<<" ";
		//~ cout<<"\n";
	//~ }
	ii sol = {-1,-1};
	forn(i,n){
		if(dista[i*m+0]!=-1) sol={i,0};
		if(dista[i*m+m-1]!=-1) sol={i,m-1};
	}
	forn(i,m){
		if(dista[0+i]!=-1) sol={0,i};
		if(dista[(n-1)*m+i]!=-1) sol={n-1,i};
	}
	if(sol==mp(-1,-1)){
		cout<<"NO\n";
	}else{
		string ans = "";
		int u = sol.fst*m+sol.snd;
		while(dista[u]!=0){
			ans+=mov(dad[u],u);
			u=dad[u];
		}
		reverse(ans.begin(),ans.end());
		cout<<"YES\n";
		cout<<sz(ans)<<"\n";
		cout<<ans<<"\n";
	}
	
	return 0;
}




