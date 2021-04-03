#include <bits/stdc++.h>
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
//#define ANARAP

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
vector<ll> dad,dist;
vector<bool> visi;
vector<vector<ll>> grap;


void bfs(ll u){
	queue<ll> q;
	q.push(u);
	visi[u]=true;
	while(!q.empty()){
		ll act = q.front();
		q.pop();
		forn(i,grap[act].size()){
			if(!visi[grap[act][i]]){
				q.push(grap[act][i]);
				visi[grap[act][i]]=true;
				dad[grap[act][i]]=act;
				dist[grap[act][i]]=dist[act]+1;
			}
		}
	}
}

ll num(ll x, ll y){
	return x*12+y;
}

ii xy(ll num){
	ll y = num%12, x = num/12;
	 return {x,y};
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll mat[12][12] = 
		{{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,0,0,0,0,0,0,1,1,0},
		{0,1,0,0,0,0,0,0,0,0,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0}};
	
	grap.resize(144);
	forn(x,12) forn(y,12){
		ll id = num(x,y); 
		if(mat[x][y]!=1){
			if(x+1<12 && mat[x+1][y]!=1){
				grap[id].pb(num(x+1,y));
			}
			if(y+1<12 && mat[x][y+1]!=1){
				grap[id].pb(num(x,y+1));
			}
			if(x-1>-1 && mat[x-1][y]!=1){
				grap[id].pb(num(x-1,y));
			}
			if(y-1>-1 && mat[x][y-1]!=1){
				grap[id].pb(num(x,y-1));
			}
		}
	}
	
	ll l, r,c;
	cin>>l;
	forn(i,l){
		visi.resize(144,false);
		dad.resize(144,-1);
		dist.resize(144,LLONG_MAX);
		
		cin>>r>>c;
		r--,c--;
		bfs(num(r,c));
		vector<pair<ll,pair<ll,ll>>> v(4);
		v[0]={dist[num(2,2)],{2,2}};
		v[1]={dist[num(2,9)],{2,9}};
		v[2]={dist[num(9,2)],{9,2}};
		v[3]={dist[num(9,9)],{9,9}};
		sort(v.begin(),v.end());
		ll act=(num(v[0].snd.fst,v[0].snd.snd));
		
		string ans="";
		while(dad[act]!=-1){
			ii pd=xy(dad[act]), ps=xy(act);
			if(ps.fst+1==pd.fst){
				ans+="U";
			}else if(ps.fst-1==pd.fst){
				ans+="D";
			}else if(ps.snd+1==pd.snd){
				ans+="L";
			}else{
				ans+="R";
			}
			act=dad[act];
		}
		
		cout<<ans.size()<<endl;
		dforn(i,ans.size()){
			cout<<ans[i];
		}
		cout<<"\n";
		
		dist.clear();
		dad.clear();
		visi.clear();
	}
	
	
	
	return 0;
}

