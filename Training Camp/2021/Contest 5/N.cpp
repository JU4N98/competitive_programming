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
	
	ll n;
	cin>>n;
	vector<string> mat(n);
	vector<vector<int>> G(27);
	vector<int> deg(27);
	
	
	forn(i,n){
		string s; cin>>s;
		while(sz(s)<100) s.pb(char('a'+26));
		mat[i]=s;
	}
	
	bool ok=true;
	forn(i,n-1){
		forn(j,100){
			if(mat[i][j]!=mat[i+1][j]){
				if(mat[i+1][j]=='{') ok=false;
				else{
					int u = mat[i][j]-'a';
					int v = mat[i+1][j]-'a';
					G[u].pb(v);
					deg[v]++;
				}
				break;
			}
		}
	}
	
	vector<int> ans;
	if(!ok) cout<<"Impossible\n";
	else{
		queue<int> q;
		int count = 0;
		forn(i,27) if(deg[i]==0){ q.push(i);}
		while(!q.empty()){
			int act = q.front(); q.pop();
			if(act!=26) ans.pb(act);
			count++;
			forn(i,sz(G[act])){
				deg[G[act][i]]--;
				if(deg[G[act][i]]==0) q.push(G[act][i]);
			}
		}
		if(count==27){
			forn(i,sz(ans)) cout<<char(ans[i]+'a');
			cout<<"\n";
		}else{
			cout<<"Impossible\n";
		}
	}
	return 0;
}




