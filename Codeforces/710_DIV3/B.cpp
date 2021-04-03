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
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,k;
		string s;
		cin>>n>>k;
		cin>>s;
		ll ini = -1, fin=-1;
		forn(i,n) if(s[i]=='*'){
			ini=i;
			break;
		}
		dforn(i,n) if(s[i]=='*'){
			fin=i;
			break;
		}
		ll ans,acum=1,ult=ini;
		for(int i=ini+k;i<fin;i+=k){
			while (s[i]!='*') i--;
			ult=i;
			acum++; 
		}
		if(ult!=fin) acum++;
		ans=acum;
		
		acum=1,ult=fin;
		for(int i=fin-k;i>ini;i-=k){
			while (s[i]!='*') i++;
			ult=i;
			acum++; 
		}
		if(ult!=ini) acum++;
		cout<<min(ans,acum)<<"\n";
	}
	
	return 0;
}




