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
		int n,k; cin>>n>>k;
		set<ii> s;
		vector<int> ans(n),count(n),borrar(k);
		forn(i,n){
			int in; cin>>in;
			s.insert({in,i});
		}
		int act=0;
		forall(it,s){
			ii p = *it;
			if(count[p.fst-1]<k){
				ans[p.snd] = act+1;
				count[p.fst-1]++;
				borrar[act]=p.snd;
				act++;
			}
			act%=k;
		}
		forn(i,act) ans[borrar[i]]=0;
		forn(i,n) cout<<ans[i]<<" ";
		cout<<"\n";
		
		
	}
	
	return 0;
}




