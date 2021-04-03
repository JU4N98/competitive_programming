#include <bits/stdc++.h>
#define forr(i,a,b) for(ll i =(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i = n-1; i>=0; i--)
#define forall(it, v) for(auto it=v.begin(); it!=v.end(); it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
#define ANARAP

#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;



int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,x,y;
	double dp[1000][1000]; //dp[i][j] prob de que el equipo j pierda en la ronda i
	while(cin>>n){
		cin>>x>>y;
		forn(i,n) forn(j,x) dp[i][j]=0.0;
		dp[x-1][n-x]=1.0;
		dforn(i,x){
			dforn(j,n-x+1){
				double n1=double(i+j),cantpar = double(n1*(n1+1))/2.0;
				double n2=double(i-1),probmenor=double(n2*(n2+1)/2);
				double n3=double(i+j),probmayor=(double(n3*(n3+1))/2.0)-(double((i)*(i+1))/2.0);
				cout<<"i "<<i<<" j "<<j<<endl;
				cout<<"probmayor "<<probmayor<<" probmenor "<<probmenor<<" cantpar "<<cantpar<<endl;
				cout<<"muere menor "<<probmenor/cantpar<<" muere grande "<<probmayor/cantpar<<endl;
				double resta=0.0;
				if(i>0){
					dp[i-1][j]+=dp[i][j]*(probmenor/cantpar);
					resta+=dp[i][j]*(probmenor/cantpar);
				}
				if(j>0){
					dp[i][j-1]+=dp[i][j]*(probmayor/cantpar);
					resta+=dp[i][j]*(probmayor/cantpar);;
				}
				dp[i][j]-=resta;
			}
		}
		forn(i,n) {
			forn(j,n) cout<<dp[i][j]<<" ";
			cout<<"\n";
		}
		double ans=0.0;
		forn(i,x) forn(j,n-x) if(n-i+j==y) ans+=dp[i][j];
		cout<<fixed<<setprecision(4)<<ans<<"\n"; 
	}
	return 0;
}
 

