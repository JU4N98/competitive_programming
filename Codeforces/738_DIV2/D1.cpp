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

struct uf{
	vector<int> root,siz;
	void init(int n){
		root.resize(n); forn(i,n) root[i]=i;
		siz.resize(n,1);
	}
	int find(int u){
		int r=u;
		while(root[r]!=r) r=root[r];
		while(root[u]!=r){
			int aux=root[u];
			root[u]=r;
			u=aux;
		}
		return r;
	}
	void uni(int u, int v){
		int r1=find(u), r2=find(v);
		if(r1!=r2){
			if(siz[r1]>siz[r2]){
				root[r2]=r1;
				siz[r1]+=r2;
			}else{
				root[r1]=r2;
				siz[r2]+=r1;
			}
		}
	}
};

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m1,m2; cin>>n>>m1>>m2;
	uf uf1,uf2;
	uf1.init(n);
	uf2.init(n);
	forn(i,m1){
		int u,v; cin>>u>>v; u--,v--;
		uf1.uni(u,v);
	}
	forn(i,m2){
		int u,v; cin>>u>>v; u--,v--;
		uf2.uni(u,v);
	}
	int ans=0;
	vector<ii> ansi;
	forn(i,n){
		forr(j,i+1,n){
			if(uf1.find(i)!=uf1.find(j) && uf2.find(j)!=uf2.find(i)){
				uf1.uni(i,j);
				uf2.uni(i,j);
				ans++;
				ansi.pb({i+1,j+1});
			}
		}
	}
	cout<<ans<<"\n";
	forn(i,sz(ansi)){
		cout<<ansi[i].fst<<" "<<ansi[i].snd<<"\n";
	}
	
	return 0;
}




