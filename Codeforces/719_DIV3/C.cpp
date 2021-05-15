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
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		vector<vector<ll>> ans(n);
		forn(i,n) ans[i].resize(n,0);
		ll act1=1; 
		if(n==2){
			cout<<"-1\n";
			continue;
		}
		forn(i,n){
			forn(j,n){
				if((i+j)%2==0){
					ans[i][j]=act1;
					act1++;
				}
			}
		}
		forn(i,n){
			forn(j,n){
				if(ans[i][j]==0){
					ans[i][j]=act1;
					act1++;
				}
				cout<<ans[i][j]<<" ";
			}
			cout<<"\n";
		}
		
	}
	
	
	return 0;
}




