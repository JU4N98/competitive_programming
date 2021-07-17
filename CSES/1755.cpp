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
	
	string s;
	cin>>s;
	ll arr[26];
	forn(i,26) arr[i]=0;
	forn(i,sz(s)) arr[s[i]-'A']++;
	ll sum=0;
	forn(i,26) if(arr[i]%2==1) sum++;
	if(sum>1){
		cout<<"NO SOLUTION\n";
	}else{
		string ans="";
		forn(i,26) if(arr[i]%2==0) forn(j,arr[i]/2) ans+= char('A'+i);
		forn(i,26) if(arr[i]%2==1) forn(j,arr[i]) ans+= char('A'+i);
		dforn(i,26) if(arr[i]%2==0) forn(j,arr[i]/2) ans+= char('A'+i);
		cout<<ans<<"\n";
	}
	
	return 0;
}




