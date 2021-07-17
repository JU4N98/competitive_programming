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
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,m;
		cin>>n>>m;
		vector<string> mat1(n),mat2(n-1);
		forn(i,n) cin>>mat1[i];
		forn(i,n-1) cin>>mat2[i];
		string ans="";
		vector<ll> letras(26,0);
		forn(j,m){
			forn(i,26) letras[i]=0;
			forn (i,n) letras[mat1[i][j]-'a']++;
			forn (i,n-1) letras[mat2[i][j]-'a']--;
			forn(i,26) if(letras[i]) ans+=char('a'+i);			
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}




