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

#define SIZE 127
int NN;
void mul(double a[SIZE][SIZE], double b[SIZE][SIZE])
{
	double res[SIZE][SIZE] = {{0}};
	forn(i, NN) forn(j, NN) forn(k, NN) res[i][j]+=a[i][k]*b[k][j];
	forn(i, NN) forn(j, NN) a[i][j]=res[i][j];
}
void powmat(double a[SIZE][SIZE], int n, double res[SIZE][SIZE])
{
	forn(i, NN) forn(j, NN) res[i][j]=(i==j);
	while(n)
	{
		if(n&1) mul(res, a), n--;
		else mul(a, a), n/=2;
	}
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,x;
	cin>>n>>x;
	NN=SIZE;
	vector<double> arr(x+1);
	forn(i,x+1) cin>>arr[i];
	double mat[SIZE][SIZE];
	double power[SIZE][SIZE];
	
	forn(i,SIZE){
		forn(j,SIZE){
			mat[i][(i^j)]+=1.0/double(SIZE);
		}
	}
	
	forn(i,x+1){
		forn(j,x+1){
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	powmat(mat,n,power);
	
	vector<double> ans(x+1,0);
	forn(i,x+1){
		forn(j,x+1){
			ans[i] += power[j][i]*arr[j];
		}
	}
	
	cout<<fixed<<setprecision(7)<<1.0-ans[0]<<"\n";
	
	return 0;
}




