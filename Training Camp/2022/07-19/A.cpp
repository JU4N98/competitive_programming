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
#define operacion(x,y) max(x,y)
using namespace std;

#ifdef ANARAP
	const int MAXN=100010;
	const int MAXY=100010;
#else
	const int MAXN=300010;
	const int MAXY=250010;
#endif

typedef pair<int,int> ii;
typedef long long ll;
typedef int Elem;
typedef int Alt;
 
const Elem neutro=0; const Alt neutro2=0;

struct RMQ{
	int sz;
	Elem t[4*MAXN];
	Alt dirty[4*MAXN];//las alteraciones pueden ser de tipo distinto a Elem
	Elem &operator[](int p) {return t[sz+p];}
	void init(int n){//O(nlgn)
		sz = 1 << (32-__builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
		forn(i, 2*sz) dirty[i] = neutro2;
	}
	void updall() {dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);} //O(n)
	void push(int n, int a, int b) {//propaga el dirty a sus hijos
		if(dirty[n] != neutro2) {// n = node of range [a,b)
			t[n] += dirty[n];//altera el nodo, modificar segun el problema
			if(n<sz){
				dirty[2*n] += dirty[n];
				dirty[2*n+1] += dirty[n];
			}
			dirty[n] = neutro2;
		}
	}
	Elem get(int i, int j, int n, int a, int b) {//O(lgn)
		if(j<=a || i>=b) return neutro;
		push(n, a, b);//corrige el valor antes de usarlo
		if(i<=a && b<=j) return t[n];//n = node of range [a,b)
		int c = (a+b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	Elem get(int i, int j) {return get(i,j,1,0,sz);}
	//altera los valores en [i, j) con una alteracion de val
	void alterar(Alt val, int i, int j, int n, int a, int b) {//O(lgn)
		push(n, a, b);
		if(j<=a || i>=b) return;
		if(i<=a && b<=j){
			dirty[n] += val; // modificar segun el problema
			push(n, a, b);
			return;
		}
		int c = (a+b)/2;
		alterar(val, i, j, 2*n, a, c), alterar(val, i, j, 2*n+1, c, b);
		t[n] = operacion(t[2*n], t[2*n+1]);//por esto es el push de arriba
	}
	void alterar(Alt val, int i, int j){alterar(val,i,j,1,0,sz);}
};

struct pto{
	int x, y, c, id;
};

bool solve(vector<pto> &ptos, int med, int k, vector<multiset<int>> &idx, RMQ &st){
	int lptr = 0, rptr = 0;
	
	bool ans = false;
	forn(lx,MAXY){
		while(rptr<sz(ptos) && ptos[rptr].x <= lx+med){
			
			pto p = ptos[rptr];
			
			if(idx[p.c].find(p.y) != idx[p.c].end()){
				idx[p.c].insert(p.y);
				rptr++;
				continue;
			}
			idx[p.c].insert(p.y);
			
			int ly=p.y, ry=p.y;
			auto ite = idx[p.c].upper_bound(p.y);
			if(ite == idx[p.c].end()){
				ry = p.y + med +1;
			}else{
				ry = min(p.y + med + 1, (*ite));
			}
			
			ite = idx[p.c].lower_bound(p.y);
			if(ite == idx[p.c].begin()){
				ly = p.y;
			}else{
				ly = max(p.y, *(prev(ite))+med+1);
			}
			
			if(max(ly,0) < min(ry,MAXY)){
				st.alterar(1,max(ly,0),min(ry,MAXY));
			}
			
			rptr++;
		}
		
		if(st.get(0,MAXY) == k) ans = true;
		
		while(lptr<sz(ptos) && ptos[lptr].x == lx){
			pto p = ptos[lptr];
			
			idx[p.c].erase(idx[p.c].find(p.y));
			if(idx[p.c].find(p.y) != idx[p.c].end()){
				lptr++;
				continue;
			}
			
			auto ite = idx[p.c].upper_bound(p.y);
			int ly=p.y, ry=p.y;
			if(ite == idx[p.c].end()){
				ry = p.y + med +1;
			}else{
				ry = min(p.y + med + 1, (*ite));
			}
			
			ite = idx[p.c].lower_bound(p.y);
			if(ite == idx[p.c].begin()){
				ly = p.y;
			}else{
				ly = max(p.y, *(prev(ite))+med+1);
			}
			
			if(max(ly,0) < min(ry,MAXY))
				st.alterar(-1,max(ly,0),min(ry,MAXY));
			
			lptr++;
		}
	}
	
	return ans;
}

int bs(vector<pto> ptos, int k){
	vector<multiset<int>> idx(k);
	RMQ st; 
	
	int l = 0, r = MAXY;
	while(l < r){
		int med = (l+r)/2;
		
		forn(i,k) idx[i].clear();
		st.init(MAXY);
		
		bool solvable = solve(ptos, med, k, idx, st);
		if(solvable){
			r = med;
		}else{
			l = med + 1;
		}
	}
	
	return l;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,k; cin >> n >> k;
	vector<pto> ptos;
	
	forn(i,n){
		pto p;
		cin >> p.x >> p.y >> p.c; 
		p.c = p.c -1;
		p.id = i;
		ptos.pb(p);
	}
	
	sort(ptos.begin(),ptos.end(),[](pto a, pto b){ return a.x<b.x || (a.x == b.x && a.id<b.id);});
	
	cout << bs(ptos,k) << "\n";
	
	return 0;
}
