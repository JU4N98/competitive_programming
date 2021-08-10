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
	
	ll n,m,q;
	cin>>n>>m>>q;
	vector<ll> bino(n+1),prefix(n+2);
	bino[0]=1;
	ll pos = n;
	forr(i,1,n+1){
		bino[i]=((bino[i-1]%m)*(pos%m))%m,pos--;
	}
	forn(i,n) cout<<bino[i]<<" ";
	cout<<"\n";
	forn(i,n+1) prefix[i+1]=((prefix[i]%m)+(bino[i]%m))%m;
	forn(i,q){
		ll l,r;
		cin>>l>>r;
		cout<<((prefix[r]-prefix[l-1])%m+m)%m<<endl;
	}
	
	return 0;
}




