#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push
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
vector<vector<ll>> mat;
vector<vector<bool>> visi;
priority_queue<pair<ll,ii>,vector<pair<ll,ii>>> pq;
ll r,c,ans;

void corregir(ii p){
	ll x =p.fst, y=p.snd;
	//cout<<corte<<endl;
	visi[x][y]=false;
	//cout<<"xy "<<x<<" "<<y<<endl;
	if(y>0){
		//cout<<"A";
		ans+=max(mat[x][y]-1-mat[x][y-1],0LL);
		mat[x][y-1]=max(mat[x][y]-1,mat[x][y-1]);
	}
	if(y<c-1){
		//cout<<"B";
		ans+=max(mat[x][y]-1-mat[x][y+1],0LL);
		mat[x][y+1]=max(mat[x][y]-1,mat[x][y+1]);
	}
	if(x>0){
		//cout<<"C";
		ans+=max(mat[x][y]-1-mat[x-1][y],0LL);
		mat[x-1][y]=max(mat[x][y]-1,mat[x-1][y]);
	}
	if(x<r-1){
		//cout<<"D";
		ans+=max(mat[x][y]-1-mat[x+1][y],0LL);
		mat[x+1][y]=max(mat[x][y]-1,mat[x+1][y]);
	}
	if(y>0 && visi[x][y-1]) pq.pb({mat[x][y-1],{x,y-1}});
	if(y<c-1 && visi[x][y+1]) pq.pb({mat[x][y+1],{x,y+1}});
	if(x>0 && visi[x-1][y]) pq.pb({mat[x-1][y],{x-1,y}});
	if(x<r-1 && visi[x+1][y]) pq.pb({mat[x+1][y],{x+1,y}});
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ans=0;
		cin>>r>>c;
		mat.resize(r);
		visi.resize(r);
		forn(i,r){
			mat[i].resize(c);
			visi[i].resize(c,true);
			forn(j,c){
				cin>>mat[i][j];
				pq.pb({mat[i][j],{i,j}});
			}
		}
		/*
		forn(i,r){
			forn(j,c){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}*/
		while(!pq.empty()){
			pair<ll,ii> p = pq.top();
			pq.pop();
			if(visi[p.snd.fst][p.snd.snd]){
				corregir(p.snd);
			}
		}
		cout<<"Case #"<<T+1<<": "<<ans<<endl;
		mat.clear();
		visi.clear();
	}
	
	return 0;
}




