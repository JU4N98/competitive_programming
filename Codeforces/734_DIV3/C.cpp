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
		vector<vector<int>> arr(5,vector<int>(n));
		forn(i,n){
			string in; cin>>in;
			vector<int> q(5);
			forn(j,sz(in)) q[in[j]-'a']++;
			forn(j,5) arr[j][i] = q[j] - (sz(in)-q[j]);
		}
		forn(i,5) sort(arr[i].begin(),arr[i].end(),[&](int a, int b){return a>b;});
		
		vector<int> ans(5),sum(5);
		forn(i,n){
			forn(j,5) if(sum[j]+arr[j][i]>0) ans[j]++,sum[j]+=arr[j][i];
		}
		
		int ansi=0;
		forn(i,5) ansi=max(ansi,ans[i]);
		cout<<ansi<<"\n";
	}
	
	return 0;
}




