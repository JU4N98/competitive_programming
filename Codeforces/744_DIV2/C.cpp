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

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin>>t;
	forn(T,t){
		int n,m,ki; cin>>n>>m>>ki;
		vector<string> mat(n); forn(i,n) cin>>mat[i];
		vector<vector<int>> bmat(n,vector<int>(m));
		dforn(i,n){
			dforn(j,m){
				int mini1=0,mini2=0,mini=0;
				if(mat[i][j]!='*') continue;
				forn(k,min(i,j)+1) if(mat[i-k][j-k]=='*') mini1++; else break;
				forn(k,min(i+1,m-j)) if(mat[i-k][j+k]=='*') mini2++; else break;
				
				mini=min(mini1,mini2);
				//~ cout<<i<<" "<<j<<" "<<mini<<endl;
				forn(k,mini) bmat[i-k][j-k]=max(bmat[i-k][j-k],mini-1);
				forn(k,mini) bmat[i-k][j+k]=max(bmat[i-k][j+k],mini-1);
				//~ if(bmat[1][5]!=0) cout<<i<<" "<<j<<endl;
			}
		}
		bool ok=true;
		forn(i,n){
			forn(j,m){
				if(mat[i][j]=='*' && bmat[i][j]<ki) ok=false;
			}
		}
		if(ok) cout<<"YES\n"; else cout<<"NO\n";
	}
	
	return 0;
}




