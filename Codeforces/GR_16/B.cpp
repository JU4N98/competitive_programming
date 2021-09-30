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
	
	ll t; cin>>t;
	forn(T,t){
		string s; cin>>s;
		int ocu[2] = {0,0};
		s[0]=='0'? ocu[0]++ : ocu[1]++;
		forr(i,1,sz(s)){
			if(s[i]!=s[i-1]){
				s[i]=='0'? ocu[0]++ : ocu[1]++;
			}
		}
		cout<<min(ocu[0],2)<<"\n";
	}
	
	
	return 0;
}




