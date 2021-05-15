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
#define EPS 0.0000001
#define ANARAP

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
vector<int> X,Y;
vector<vector<double>> A;
vector<double> b,c;
double z;
int n,m;

void pivot(int x, int y){
	swap(X[y],Y[x]);
	b[x]/=A[x][y];
	forn(i,m) if(i!=y) A[x][i]/=A[x][y];
	A[x][y]=1.0/A[x][y];
	forn(i,n) if(i!=x && abs(A[i][y])>EPS){
		b[i]-=A[i][y]*b[x];
		forn(j,m) if(j!=y) A[i][j]-=A[i][y]*A[x][j];
		A[i][y]=-A[i][y]*A[x][y];
	}
	z+=c[y]*b[x];
	forn(i,m) if(i!=y) c[i]-= c[y]*A[x][i];
	c[y]= -c[y]*A[x][y];
}

pair<double,vector<double>> simplex(
vector<vector<double>> _A, vector<double> _b, vector<double> _c){
	A=_A; b=_b; c=_c;
	n=b.size();m=c.size(); z=0.;
	X=vector<int>(m); Y=vector<int>(n);
	forn(i,m) X[i]=i;
	forn(i,n) Y[i]=i+m;
	while(1){
		int x=-1,y=-1;
		double mn=-EPS;
		forn(i,n) if(b[i]<mn) mn=b[i],x=i;
		if(x<0) break;
		forn(i,m) if(A[x][i]<-EPS){y=i;break;}
		assert(y>=0);
		pivot(x,y); 
	}
	while(1){
		double mx=EPS;
		int x=-1,y=-1;
		forn(i,m) if(c[i]>mx) mx=c[i],y=i;
		if(y<0) break;
		double mn=1e200;
		forn(i,n) if(A[i][y]>EPS && b[i]/A[i][y]<mn) mn=b[i]/A[i][y],x=i;
		assert(x>=0);
		pivot(x,y);
	}
	vector<double> r(m);
	forn(i,n) if(Y[i]<m) r[Y[i]]=b[i];
	return {z,r};
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	vector<vector<double>> _A(n);
	forn(i,n) _A[i].rsz(m);
	vector<double> _b(n),_c(m);
	forn(i,n) cin>>_b[i];
	forn(i,m){
		forn(j,n){
			cin>>_A[j][i];
			//_A[j][i]/=100.0;
		}
		cin>>_c[i];
	}
	cout<<fixed<<setprecision(2)<<simplex(_A,_b,_c).fst<<"\n";
	
	
	return 0;
}




