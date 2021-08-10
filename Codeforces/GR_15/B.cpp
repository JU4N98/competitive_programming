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
	
	int t;
	cin>>t;
	forn(T,t){
		int n; cin>>n;
		vector<vector<int>> mat(n);
		forn(i,n){
			mat[i].resize(5);
			forn(j,5) cin>>mat[i][j];
		}
		int candi=0;
		forr(i,1,n){
			int count=0;
			forn(j,5) if(mat[i][j]>mat[candi][j]) count++ ;
			if(count<3) candi=i ;
		}
		bool ans = true;
		forn(i,n){
			if(i==candi) continue;
			int count=0;
			forn(j,5) if(mat[i][j]>mat[candi][j]) count++ ;
			if(count<3) ans=false ;
		}
		ans? cout<<candi+1<<"\n" : cout<<"-1\n";
		
	}
	
	return 0;
}




