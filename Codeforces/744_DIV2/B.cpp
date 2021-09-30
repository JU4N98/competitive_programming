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
	
	int t; cin>>t;
	forn(T,t){
		int n; cin>>n;
		vector<ll> arr(n); forn(i,n) cin>>arr[i];
		vector<vector<ll>> ans;
		
		forn(i,n){
			int mini=i;
			forr(j,i+1,n) if(arr[j]<arr[mini]) mini=j;
			if(mini!=i){
				vector<ll> aux;
				aux.pb(i);
				aux.pb(mini);
				aux.pb(mini-i);
				ans.pb(aux);
				
				vector<ll> aux2;
				aux2.pb(arr[mini]);
				forr(j,i,mini) aux2.pb(arr[j]);
				forn(j,sz(aux2)) arr[j+i]=aux2[j];
			}
		}
		cout<<sz(ans)<<"\n";
		forn(i,sz(ans)) cout<<ans[i][0]+1<<" "<<ans[i][1]+1<<" "<<ans[i][2]<<"\n";
		
	}
	
	return 0;
}




