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

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin>>n;
	vector<ll> arr(n);
	vector<vector<ll>> mat(n);
	forn(i,n){
		cin>>arr[i];
		mat[i].resize(n,-1LL);
	}
	forn(i,n){
		ll x=i,y=i;
		forn(j,arr[i]){
			mat[x][y]=arr[i];
			if(y==0) x++;
			else if(mat[x][y-1]!=-1) x++;
			else y--;
		}
	}
	forn(i,n){
		forn(j,n){
			if(j<=i) cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	
	return 0;
}




