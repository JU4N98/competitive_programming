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
		vector<string> bi(2);
		cin>>bi[0]>>bi[1];
		vector<int> sum;
		int ans=0;
		forn(i,n) sum.pb((bi[0][i]-'0')+(bi[1][i]-'0'));
		forn(i,n) if(sum[i]==1) ans+=2,sum[i]=-1;
		forn(i,n) if(sum[i]==0){
			if(i>0 && sum[i-1]==2) ans+=2,sum[i]=-1,sum[i-1]=-1;
			else if(i<n-1 && sum[i+1]==2) ans+=2,sum[i]=-1,sum[i+1]=-1;
			else ans++;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}




