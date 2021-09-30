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
typedef pair<ll,ll> ii;

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
		set<ii> s;
		forn(i,n){
			ii p;
			cin>>p.fst;
			p.fst*=-1LL;
			p.snd=i;
			if(p.fst<0) s.insert(p);
		}
		vector<ii> ans;
		while(!s.empty()){
			ii p1 = *(s.begin());
			s.erase(s.begin());
			if(s.empty()) break;
			ii p2 = *(s.begin());
			s.erase(s.begin());
			p1.fst+=1;
			p2.fst+=1;
			ans.pb({p1.snd+1LL,p2.snd+1LL});
			if(p1.fst<0) s.insert(p1);
			if(p2.fst<0) s.insert(p2);
		}
		cout<<sz(ans)<<"\n";
		forn(i,sz(ans)) cout<<ans[i].fst<<" "<<ans[i].snd<<"\n";
	}
	
	return 0;
}




