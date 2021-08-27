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
		ii p1,p2,p3;
		cin>>p1.fst>>p1.snd;
		cin>>p2.fst>>p2.snd;
		cin>>p3.fst>>p3.snd;
		int ans=0;
		if((p1.fst==p2.fst && p1.fst==p3.fst && p3.snd>min(p1.snd,p2.snd) && p3.snd<max(p1.snd,p2.snd)) 
		|| (p1.snd==p2.snd && p1.snd==p3.snd && p3.fst>min(p1.fst,p2.fst) && p3.fst<max(p1.fst,p2.fst))) ans+=2;
		ans += abs(p1.fst-p2.fst) + abs(p1.snd-p2.snd);
		cout<<ans<<"\n";
	}
	
	return 0;
}




