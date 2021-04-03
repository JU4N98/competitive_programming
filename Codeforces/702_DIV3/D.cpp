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
		vector<ii> arr(n);
		vector<vector<ll>> grafo(n);
		forn(i,n) grafo[i].resize(2,-1);
		forn(i,n){
			ll aux;
			cin>>aux;
			arr[i]={aux-1,i};
		}
		sort(arr.begin(),arr.end());
		reverse(arr.begin(),arr.end());
		ll root=arr[0].snd;
		vector<ll> ans(n);
		forr(i,1,n){
			ll act=root,idx =arr[i].snd;
			ll prof=0;
			bool ok=true;
			while(ok){
				if(idx<act){
					if(grafo[act][0]!=-1) act = grafo[act][0];
					else{
						grafo[act][0]=idx;
						ok=false;
					}
				}else{
					if(grafo[act][1]!=-1) act = grafo[act][1];
					else{ 
						grafo[act][1]=idx;
						ok=false;
					}
				}
				prof++;
			}
			ans[idx]=prof;
		}
		forn(i,n) cout<<ans[i]<<" ";
		cout<<endl;
	}
	
	return 0;
}




