#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(ll i=n-1;i>=0;i--)
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

ll gauss(ll n){ return n*(n+1)/2;}

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
		ll n; cin>>n;
		string s; cin>>s;
		ll ini=0,fin=0,ans=0;
		forn(i,n) if(s[i]=='1'){ ini=i; break;}
		ans+=gauss(ini);
		dforn(i,n) if(s[i]=='1'){fin=i; break;}
		ans+=gauss(n-1-fin);
		forr(i,ini,fin){
			while(i<fin && s[i]=='1') i++;
			int cant=0;
			while(i<fin && s[i]=='0') i++,cant++;
			if(i<n){
				if(cant%2==0){
					ans+=gauss(cant/2)*2;
				}else{
					ans+=gauss(cant/2);
					ans+=gauss(cant/2+1);
				}
			}
		}
		cout<<"Case #"<<T+1<<": "<<ans<<"\n";
	}
	
	return 0;
}




