#include <bits/stdc++.h>
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
		string a ,b, auxa="",auxb="";
		cin>>a>>b;
		forn(i,b.size()){
			auxa+=a;
		}
		forn(i,a.size()){
			auxb+=b;
		}
		string ans="";
		bool sol=true;
		forn(i,auxa.size()){
			if(auxa[i]==auxb[i]){
				ans+=auxa[i];
				if((i+1)%a.size()==0 && (i+1)%b.size()==0) break;
			}else{
				sol=false;
			}
		}
		if(sol) cout<<ans<<"\n";
		else cout<<-1<<"\n";
	}
	
	
	
	return 0;
}

