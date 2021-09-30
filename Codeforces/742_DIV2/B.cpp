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
	
	vector<int> x(300010);
	x[0]=0;
	forr(i,1,300010) x[i]=x[i-1]^i;
	
	int t; cin>>t;
	forn(T,t){
		int a,b,bi; cin>>a>>b;
		int ans=a;
		int xi = x[a-1];
		int nec=0,pot=1;
		bi=b;
		while(max(b,xi)>0){
			if(((b&1) && !(xi&1)) ||
			(!(b&1) && (xi&1))) nec+=pot;
			pot*=2;
			xi/=2;
			b/=2;
		}
		if(x[a-1]==bi) cout<<ans<<"\n";
		else if(nec!=a) cout<<ans+1<<"\n";
		else cout<<ans+2<<"\n";
	}
	
	return 0;
}




