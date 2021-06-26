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
//#define ANARAP

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
vector<vector<char>> mat; 
vector<vector<bool>> visi;
bool ok;
ll n,m;

void colorear(ll x,ll y){
	if(visi[x][y]) return;
	visi[x][y]=true;
	ll arrx[4]={-1,1,0,0},arry[4]={0,0,-1,1};
	forn(i,4){
		ll xi=x+arrx[i], yi=y+arry[i];
		if(x+arrx[i]>-1 && x+arrx[i]<n && y+arry[i]>-1 && y+arry[i]<m){
			if(mat[x][y]=='R'){
				if(mat[xi][yi]=='R'){
					ok=false;
					return;
				}
				if(mat[xi][yi]=='.'){
					mat[xi][yi]='W';
				}
				colorear(xi,yi);
			}else{
				if(mat[xi][yi]=='W'){
					ok=false;
					return;
				}
				if(mat[xi][yi]=='.'){
					mat[xi][yi]='R';
				}
				colorear(xi,yi);
			}
		}
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
	
	ll t;
	cin>>t;
	forn(T,t){
		cin>>n>>m;
		mat.resize(n);
		visi.resize(n);
		bool allp=true;
		ii p;
		forn(i,n){
			string in;
			cin>>in;
			mat[i].resize(m);
			visi[i].assign(m,false);
			forn(j,m){
				mat[i][j]=in[j];
				if(mat[i][j]!='.') {allp=false;p={i,j};}
			}
		}
		if(allp) mat[0][0]='R',p={0,0};
		ok=true;
		colorear(p.fst,p.snd);
		if(ok){
			cout<<"YES\n";
			forn(i,n){
				forn(j,m) cout<<mat[i][j];
				cout<<"\n";
			}
		}else{
			cout<<"NO\n";
		}
		
	}
	
	return 0;
}




