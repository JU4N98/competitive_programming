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

ii cast(string s){
	ii ans = {0,0};
	forr(i,1,sz(s)){
		ans.fst*=10;
		ans.fst+=(s[i]-'0');
		if(s[i]=='.') break;
	}
	ans.snd = (s[sz(s)-2]-'0')*10+s[sz(s)-1]-'0';
	return ans;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin>>n;
	ii ans = {0,0};
	string s;
	cin>>s;
	ans = cast(s);
	ll acum=0;
	forn(i,n){
		cin>>s;
		ans.snd += cast(s).snd;
		if(ans.snd%100!=0) acum++;
	}
	cout<<acum<<"\n";
	
	
	return 0;
}




