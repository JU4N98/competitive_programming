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
		ll n,m;
		cin>>n>>m;
		m=min(n,m);
		string s;
		cin>>s;
		forn(i,m){
			forn(j,n){
				int sum=0;
				if(j>0 && s[j-1]=='1') sum++;
				if(j<n-1 && s[j+1]=='1') sum++;
				if(s[j]=='0' && sum==1) s[j]='2';
			}
			forn(j,n) if(s[j]=='2') s[j]='1';
			//cout<<s<<endl;
		}
		cout<<s<<"\n";
	}
	
	return 0;
}




