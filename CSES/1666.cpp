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
vector<ii> edges,ans;
vector<int> root,tam;


int find(int u){
	int r=u;
	while(r!=root[r]) r=root[r];
	while(u!=root[u]){
		int aux=root[u];
		root[u]=r;
		u=aux;
	}
	return r;
}

void unify(int u, int v){
	int r1=find(u),r2=find(v);
	if(r1==r2) return;
	if(tam[r1]>tam[r2]){
		root[r2]=r1;
		tam[r1]+=tam[r2];
	}else{
		root[r1]=r2;
		tam[r2]+=tam[r1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m;
	cin>>n>>m;
	
	root.resize(n);
	forn(i,n) root[i]=i;
	tam.resize(n,1);
	forn(i,m){
		int a,b;
		cin>>a>>b;
		edges.pb({a-1,b-1});
	}
	forn(i,m) unify(edges[i].fst,edges[i].snd);
	set<int> s;
	forn(i,n) s.insert(find(i));
	int u = *(s.begin());
	s.erase(s.begin());
	forall(it,s){
		ans.pb({u,*it});
	}
	cout<<sz(ans)<<"\n";
	forn(i,sz(ans)) cout<<ans[i].fst+1<<" "<<ans[i].snd+1<<"\n";
	
	return 0;
}




