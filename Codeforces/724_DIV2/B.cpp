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
	
	vector<string> comp;
	forn(i,26){
		char ci = ('a'+i);
		string s1;
		s1+=ci;
		comp.pb(s1);
		forn(j,26){
			char ji = ('a'+j);
			string s2;
			s2+=ci;
			s2+=ji;
			comp.pb(s2);
			forn(k,26){
				char ki = ('a'+k);
				string s3;
				s3+=ci;
				s3+=ji;
				s3+=ki;
				comp.pb(s3);
			}
		}
	}
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		string s;
		cin>>s;
		set<string> ss;
		forn(i,n){
			string sub="";
			forr(j,i,i+3){
				sub+=s[j];
				ss.insert(sub);
			}
		}
		string ans="aaaa";
		forn(i,sz(comp)){
			if(ss.find(comp[i])==ss.end() && sz(ans)>sz(comp[i])) ans=comp[i];
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}




