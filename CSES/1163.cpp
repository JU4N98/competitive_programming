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
	
	ll n,x;
	cin>>x>>n;
	vector<int> arr(n),arr2;
	forn(i,n) cin>>arr[i];
	arr2=arr;
	sort(arr.begin(),arr.end());
	if(arr[0]!=0) arr.pb(0);
	if(arr[n-1]!=x) arr.pb(x);
	sort(arr.begin(),arr.end());
	
	int ans=0;
	set<ii> s;
	forn(i,sz(arr)-1){
		s.insert({arr[i],arr[i+1]});
		ans=max(arr[i+1]-arr[i],ans);
	}
	

	vector<int> arrans;
	arrans.pb(ans);
	dforn(i,n){
		cout<<"\n\n";
		auto ite1 = s.lower_bound({arr2[i],0});
		auto ite2 = prev(ite1);
		ii p1 = *ite1, p2=*ite2;
		ans = max(p1.snd-p2.fst,ans);
		arrans.pb(ans);
		s.erase(ite1);
		s.erase(ite2);
		s.insert({p2.fst,p1.snd});
	}
	
	dforn(i,sz(arrans)-1) cout<<arrans[i]<<" ";
	cout<<"\n";
	
	return 0;
}




