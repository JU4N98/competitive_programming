#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP
#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
vector<vector<int>> mat;
vector<int> root,size1;
int ansa;
int n,m,q;

int find(int u){
	int r=u;
	while(root[r]!=r) r=root[r];
	while(root[u]!=u){
		int aux = root[u];
		root[u]=r;
		u=aux;
	}
	return r;
}

void unify(int u, int v){
	int r1=find(u), r2=find(v);
	if(r1==r2) return;
	ansa--;
	if(size1[r1]>size1[r2]){
		root[r2]=r1;
		size1[r1]+=size1[r2];
	}else{
		root[r1]=r2;
		size1[r2]+=size1[r1];
	}
}

int id(int x, int y){
	return x*m+y;
}

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n>>m>>q;
	mat.resize(n);
	root.resize(n*m,0);
	size1.resize(n*m,1);
	forn(i,n) mat[i].resize(m,0);
	
	vector<pair<ii,ii>> qu;
	forn(i,n*m) root[i]=i;
	forn(i,q){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x1--; y1--; x2--; y2--;
		qu.pb({{x1,y1},{x2,y2}});
		for(int i=min(x1,x2); i<=max(x1,x2); i++) for(int j=min(y1,y2); j<=max(y1,y2); j++) mat[i][j]++;
	}
	vector<ll> ans;
	reverse(qu.begin(),qu.end());
	
	ansa=n*m;
	forn(i,n){
		forn(j,m){
			if(mat[i][j]>0){
				ansa--;
				continue;
			}
			if(i>0 && mat[i-1][j]==0) unify(id(i,j),id(i-1,j));
			if(i<n-1 && mat[i+1][j]==0) unify(id(i,j),id(i+1,j));
			if(j>0 && mat[i][j-1]==0) unify(id(i,j),id(i,j-1));
			if(j<m-1 && mat[i][j+1]==0) unify(id(i,j),id(i,j+1));
		}
	}
	
	ans.pb(ansa);
	forn(k,q){
		int x1=qu[k].fst.fst,y1=qu[k].fst.snd,x2=qu[k].snd.fst,y2=qu[k].snd.snd;
		for(int i=min(x1,x2); i<=max(x1,x2); i++) for(int j=min(y1,y2); j<=max(y1,y2); j++){
			mat[i][j]--;
			if(mat[i][j]==0) ansa++;
		}
		
		for(int i=min(x1,x2); i<=max(x1,x2); i++){
			for(int j=min(y1,y2); j<=max(y1,y2); j++){
				if(mat[i][j]>0) continue;
				if(i>0 && mat[i-1][j]==0) unify(id(i,j),id(i-1,j));
				if(i<n-1 && mat[i+1][j]==0) unify(id(i,j),id(i+1,j));
				if(j>0 && mat[i][j-1]==0) unify(id(i,j),id(i,j-1));
				if(j<m-1 && mat[i][j+1]==0) unify(id(i,j),id(i,j+1));
			}
		}
		ans.pb(ansa);
	}
	reverse(ans.begin(),ans.end());
	forr(i,1,ans.size()) cout<<ans[i]<<"\n";
	
	return 0;
}
 
