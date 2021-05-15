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
		ll n,m;
		cin>>n>>m;
		vector<vector<ll>> mat(n),ans(n);
		vector<vector<bool>> bmat(n);
		vector<pair<ll,pair<ll,ll>>> arr;
		forn(i,n){
			ll aux;
			ans[i].resize(m,-1LL);
			bmat[i].resize(m,true);
			forn(j,m){
				cin>>aux;
				mat[i].pb(aux);
				arr.pb({aux,{i,j}});
			}
		}
		sort(arr.begin(),arr.end());
		forn(i,m){
			ll aux=arr[i].fst,ai=arr[i].snd.fst,aj=arr[i].snd.snd;
			ans[ai][i]=aux;
			bmat[ai][aj]=false;
		}
		
		forn(i,n){
			ll pos=0;
			forn(j,m){
				if(bmat[i][j]){
					while(ans[i][pos]!=-1) pos++;
					ans[i][pos]=mat[i][j];
				}
			}
		}
		
		forn(i,n){
			forn(j,m){
				cout<<ans[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}




