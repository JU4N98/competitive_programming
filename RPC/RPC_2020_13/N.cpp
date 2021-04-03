#include <bits/stdc++.h>
#define forr(i, a,b) for(int i=(a); i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
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
typedef int tipo;
map<string,ll> indice;
ll MAX=0;



tipo oper(const tipo &a, const tipo &b){
	return a+b;
}

struct node{
	tipo v; node *l, *r;
	node(tipo v) : v(v), l(NULL), r(NULL) {}
	node(node *l, node *r): l(l), r(r){
		if(!l) v=r->v;
		else if(!r) v= l->v;
		else v = oper(l->v,r->v);
	}
};

node *build(int tl, int tr){
	if(tl+1 == tr) return new node(0);
	int tm = (tl+tr)>>1;
	return new node(build(tl,tm),build(tm+1,tr));
}

node *update(int pos, node *t, int tl, int tr){
	if(tl+1==tr) return new node(t->v+1);
	int tm = (tl+tr)>>1;
	if(pos<tm) return new node (update(pos,t->l,tl,tm),t->r);
	else return new node (t->l,update(pos,t->r,tm,tr));
}

tipo get(int l, int r, node *t, int tl, int tr){
	if(l==tl && tr==r){ 
		return t->v; 
	}
	int tm = (tl+tr)>>1;
	if(r<=tm) return get(l,r,t->l,tl,tm);
	else if(l>=tm) return get(l,r,t->r,tm,tr);
	return oper(get(l,tm,t->l,tl,tm),get(tm,r,t->r,tm,tr));
}

void substrings(string s){
	int tam=s.size();
	forn(i,tam){
		forn(j,tam){
			string substring="";
			forr(k,i,max(tam-j,i)) substring+=s[k];
			if(substring!="" && indice.find(substring)==indice.end()){
				indice[substring]=MAX;
				MAX++;
			}
		}
	}
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,q;
	cin>>n>>q;
	vector<string> strings(n);
	
	forn(i,n) cin>>strings[i];
	forn(i,q){
		ll a,b;
		cin>>a>>b;
	}
	
	substrings("banana");
	
	
	return 0;
}
