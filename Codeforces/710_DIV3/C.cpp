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
		string a,b;
		cin>>a>>b;
		map<string,ll> m1,m2;
		forn(i,a.size()){
			forr(i2,i,a.size()){
				string aux="";
				forr(k,i,i2+1) aux+=a[k];
				if(m1.find(aux)==m1.end()) m1[aux]=(i-0)+(a.size()-i2-1);
				else{
					ll val = m1[aux], val2 = (i-0)+(a.size()-i2-1);
					m1[aux] = min(val,val2);
				}
			}
		}
		
		forn(j,b.size()){
			forr(j2,j,b.size()){
				string aux="";
				forr(k,j,j2+1) aux+=b[k];
				if(m2.find(aux)==m2.end()) m2[aux]=(j-0)+(b.size()-j2-1);
				else{
					ll val = m2[aux], val2 = (j-0)+(b.size()-j2-1);
					m2[aux] = min(val,val2);
				}
			}
		}
		ll ans=a.size()+b.size();
		forall(ite,m1){
			string s = ite->first;
			ll act = ite->second;
			if(m2.find(s)==m2.end()) continue;
			act+=m2[s];
			ans=min(ans,act);
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}




