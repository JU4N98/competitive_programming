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
const int posi = 3628800;

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
		int n; cin>>n;
		vector<int> vec(n);
		forn(i,n) vec[i]=i+1;
		
		long double ans=0;
		forn(i,posi){
			int maxi=0;
			long double ansi=0;
			forn(j,n){
				if(vec[j]>maxi){
					ansi+=1.0;
					maxi=vec[j];
				}
			}
			next_permutation(vec.begin(),vec.end());
			ansi/=double(posi);
			ans+=ansi;
		}
		cout<<"Case #"<<T+1<<": ";
		cout<<fixed<<setprecision(7)<<ans<<"\n";
	}
	return 0;
}




