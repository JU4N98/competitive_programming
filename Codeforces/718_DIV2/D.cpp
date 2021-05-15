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

const int INF = INT_MAX;
vector<ii> G[250000];
int dp[11][250000];

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	
	forn(i,n){
		forn(j,m-1){
			int in; cin>>in;
			G[i*m+j].pb({i*m+j+1,in});
			G[i*m+j+1].pb({i*m+j,in});
		}
	}
	forn(i,n-1){
		forn(j,m){
			int in; cin>>in;
			G[i*m+j].pb({(i+1)*m+j,in});
			G[(i+1)*m+j].pb({i*m+j,in});
		}
	}
	
	if(k%2==1){
		forn(i,n){
			forn(j,m){
				cout<<"-1 ";
			}
			cout<<"\n";
		}
		return 0;
	}
	
	
	int x,y;
	forn(i,k/2+1) forn(j,n*m) dp[i][j]=INF;
	forn(i,n*m) dp[0][i]=0;
	
	
	forn(j2,k/2){
		forn(i2,n*m){
			if(dp[j2][i2]!=INF){
				forn(i3,sz(G[i2])){
					x=G[i2][i3].fst/m,y=G[i2][i3].fst%m;
					if(x>=0 && x<n 
					&& y>=0 && y<m){
						dp[j2+1][x*m+y]=min(dp[j2+1][x*m+y],dp[j2][i2]+G[i2][i3].snd);
					}
				}
			}	
		}
	}
	
	forn(i,n){
		forn(j,m){
			cout<<dp[k/2][i*m+j]*2<<" ";
		}
		cout<<"\n";
	}
	
	 	
	return 0;
}




