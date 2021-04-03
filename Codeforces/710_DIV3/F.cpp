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
#define ANARAP

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
		vector<ii> ptos(n);
		forn(i,n){
			int aux;
			cin>>aux;
			ptos[i].fst=aux;
		}
		forn(i,n){
			int aux;
			cin>>aux;
			ptos[i].snd=aux;
		}
		sort(ptos.begin(),ptos.end());
		int ans=0;
		forn(i,n-1){
			int r1=ptos[i].fst, c1=ptos[i].snd, r2=ptos[i+1].fst,c2=ptos[i+1].snd;
			if(c1==c2){
				if((c1+r1)%2==1) ans++;
			}else{
				if((c1+r1)%2==0) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}




