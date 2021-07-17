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
	
	int t,mat[21][21];
	cin>>t;
	forn(T,t){
		int h,w;
		cin>>h>>w;
		forn(i,h) forn(j,w) mat[i][j]=0;
		mat[0][0]=1;
		mat[h-1][0]=1;
		mat[0][w-1]=1;
		mat[h-1][w-1]=1;
		
		forr(i,1,h-1){
			if(mat[i-1][0]==0 && mat[i+1][0]==0) mat[i][0]=1;
			if(mat[i-1][w-1]==0 && mat[i+1][w-1]==0) mat[i][w-1]=1;
		}
		forr(i,1,w-1){
			if(mat[0][i-1]==0 && mat[0][i+1]==0) mat[0][i]=1;
			if(mat[h-1][i-1]==0 && mat[h-1][i+1]==0) mat[h-1][i]=1;
		}
		
		forn(i,h){
			forn(j,w) cout<<mat[i][j];
			cout<<"\n";
		}
		cout<<"\n";
	}

	return 0;
}




