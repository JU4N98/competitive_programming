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
		int n,d; cin>>n>>d;
		vector<int> arr(n); forn(i,n) cin>>arr[i];
		vector<bool> visi(n);
		int ans=-1;
		forn(i,n){
			if(!visi[i] && arr[i]==0){
				visi[i]=true;
				int f=i,s = (i+d)%n;
				int aux=0;
				ans=max(ans,aux);
				while(!visi[s]){
					if(arr[s]==1) aux++; else aux=0;
					visi[s]=true;
					s=(s+d)%n;
					f=(f+d)%n;
					ans=max(ans,aux);
				}
			}
		}
		bool ok=true;
		forn(i,n) if(!visi[i]){ ok=false;break;}
		if(!ok) cout<<"-1\n";
		else cout<<ans<<"\n";
	}
	
	return 0;
}




