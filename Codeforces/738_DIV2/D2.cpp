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
			if(r1<r2){
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
	multiset<pair<ii,int>> ms;
	forn(i,n){
		ms.insert({{uf1.root[i],uf2.root[i]},i});
	}
	
		pair<ii,int> act = *(ms.begin());
		act.fst.fst++,act.fst.snd++;
		while(ms.lower_bound(act)!=ms.end()){
			pair<ii,int> act2 = *(ms.upper_bound(act));
			if(uf1.find(act.snd)!=uf1.find(act2.snd) &&
			uf2.find(act.snd)!=uf2.find(act2.snd)){
				ans++;
				uf1.uni(act.snd,act2.snd);
				uf2.uni(act.snd,act2.snd);
				ms.erase(act2);
				ansi.pb({act.snd,act2.snd});
			}
			act=act2;
			act.fst.fst++;act.fst.snd++;
		}
	
	cout<<ans<<"\n";
	forn(i,sz(ansi)) cout<<ansi[i].fst+1<<" "<<ansi[i].snd<<"\n";
	
	return 0;
}




