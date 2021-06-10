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
#define ANARAP
#define MAXN 100010
#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
vector<ll> id,szi;
vector<ii> E;

ll find(ll u){
	ll r=u;
	while(id[r]!=r) r=id[r];
	while(id[u]!=r){
		ll aux=id[u];
		id[u]=r;
		u=aux;
	}
	return r;
}

void unify(ll u,ll v){
	ll r1=find(u),r2=find(v);
	if(r1==r2) return;
	else if(szi[r1]>szi[r2]){
		id[r2]=r1;
		szi[r1]+=szi[r2];
	}else{
		id[r1]=r2;
		szi[r2]+=szi[r1];
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
	
	ll n,m;
	cin>>n>>m;
	szi.resize(n,1);
	id.resize(n);
	forn(i,n) id[i]=i;
	
	forn(i,m){
		ll u,v;
		cin>>u>>v;
		E.pb({u-1,v-1});
	}
	
	ll cant=0;
	forn(i,m){
		if(find(E[i].fst)!=find(E[i].snd)){ unify(E[i].fst,E[i].snd);cant++;}
	}
	
	cout<<m-cant<<endl;
	
	
	return 0;
}




