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
	
	int criba[101];
	forn(i,101) criba[i]=true;
	criba[1]=false;
	forr(i,2,101){
		if(criba[i]) for(int j=i+i;j<101;j+=i) criba[j]=false;
	}
	
	int t; cin>>t;
	forn(T,t){
		int n; cin>>n;
		string s; cin>>s;
		ii ans={101,101};
		forn(i,n){
			forr(j,i+1,n){
				int aux = (s[i]-'0')*10 +(s[j]-'0');
				if(!criba[aux]){
					ans=min(ans,{2,aux});
				}
			}
			if(s[i] && !criba[s[i]-'0']){
				ans=min(ans,{1,s[i]-'0'});
			}
		}
		cout<<ans.fst<<"\n"<<ans.snd<<"\n";
		
	}
	
	return 0;
}




