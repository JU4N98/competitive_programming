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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin>>t;
	forn(T,t){
		int n,m; cin>>n>>m;
		vector<vector<bool>> mat(n,vector<bool>(m));
		forn(i,n){
			string s; cin >> s;
			forn(j,m) mat[i][j] = s[j]=='1';
		}
		bool elegant = true;
		forn(i,n){
			forn(j,m){
				//~ cout<<"\n";
				//~ cout<<"i: "<< i << " j: "<<j<<"| ";
				if(j-1>-1){
					if(i-1>-1){
						elegant = !(mat[i-1][j] &&
						mat[i][j-1] && mat[i][j] &&
						!mat[i-1][j-1]);
						// 0 1
						// 1 1
 					}
 					//~ cout << elegant << " ";
 					if(!elegant) break;
					if(i+1<n){
						elegant = !(mat[i+1][j] &&
						mat[i][j-1] && mat[i][j] &&
						!mat[i+1][j-1]);
						//1 1
						//0 1
					}
					//~ cout << elegant << " ";
					if(!elegant) break;
				}
				if(j+1<m){
					if(i-1>-1){
						elegant = !(mat[i-1][j] &&
						mat[i][j+1] && mat[i][j] &&
						!mat[i-1][j+1]);
						//1 0
						//1 1
					}
					//~ cout << elegant << " ";
					if(!elegant) break;
					if(i+1<n){
						elegant = !(mat[i+1][j] &&
						mat[i][j+1] && mat[i][j] &&
						!mat[i+1][j+1]);
						//1 1
						//1 0
					}
					//~ cout << elegant << " ";
					if(!elegant) break;
				}
			}
			if(!elegant) break;
		}
		if(elegant) cout << "YES\n";
		else cout << "NO\n";
	}
	
	
	return 0;
}



