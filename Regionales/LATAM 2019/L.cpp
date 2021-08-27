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

bool check(vector<vector<int>> &mat, int n){
	int maxdim=0;
	n--;
	for(int j=0; j+n<sz(mat[0]); j++){
		int act=0;
		forn(i,sz(mat)){
			int sum = mat[i][j+n];
			if(j-1>-1) sum-=mat[i][j-1];
			if(sum==n+1 || sum==0) act++;
			else{
				maxdim=max(maxdim,act);
				act=0;
			}
		}
		maxdim=max(maxdim,act);
	}
	bool ans= (maxdim>=n+1);
	return ans;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m; cin>>n>>m;
	vector<vector<int>> mat(n,vector<int>(m));
	forn(i,n){
		string in; cin>>in;
		forn(j,m) if(in[j]=='G') mat[i][j]=1;
	}
	forn(i,n){
		forr(j,1,m){
			mat[i][j]+=mat[i][j-1];
		}
	}
	
	int l=1,r=min(n,m);
	while(l<r){
		int med = (l+r+1)/2;
		if(check(mat,med)){
			l=med;
		}else{
			r=med-1;
		}
	}
	cout<<l*l<<"\n";
	
	return 0;
}




