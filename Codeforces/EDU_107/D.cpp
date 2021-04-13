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
	
	ll n, k;
	cin>>n>>k;
	
	vector<vector<ll>> graph(k);
	vector<ll> out(k,0),ans;
	
	forn(i,k){
		graph[i].resize(k);
		forn(j,k){
			graph[i][j]=j;
		}
		out[i]=k;
	}
	
	stack<ll> s;
	s.push(0);
	while(!s.empty()){
		ll u = s.top();
		if(out[u]==0){
			ans.pb(u);
			s.pop();
		}else{
			out[u]--;
			s.push(graph[u][out[u]]);
		}
	}
	
	string str="";
	forn(i,ans.size()-1) str+=char('a'+ans[i]);
	while(str.size()<n) str+=str;
	forn(i,n) cout<<str[i];
	cout<<"\n";
	
	return 0;
}




