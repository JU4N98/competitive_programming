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
	
	ll n;
	string s;
	cin>>n;
	cin>>s;
	vector<ll> f1(26,-1),f2(26,-1),per(26,-1);
	vector<bool> ans(26,false);
	forn(i,sz(s)){
		int li=s[i]-'a';
		if(f1[li]==-1) f1[li]=i;
		else if(f2[li]==-1){
			f2[li]=i;
			per[li]=f2[li]-f1[li];
			ans[li]=true;
		}
	}
	
	forn(i,26){
		while(per[i]!=-1 && f1[i]-per[i]>=0){
			f1[i]-=per[i];
		}
		for(int j=f1[i];j<sz(s);j+=per[i]){
			if(s[j]!=char('a'+i)){
				ans[i]=false;
				break;
			}else{
				s[j]='?';
			}
		}
	}
	forn(i,sz(s)) if(s[i]!='?') ans[s[i]-'a']=false;
	
	bool ok=false;
	forn(i,26) if(ans[i]==true){ ok=true;break;}
	if(ok) {
		forn(i,26) if(ans[i]) cout<<char('a'+i);
		cout<<"\n";
	}else{
		cout<<"-1\n";
	}
	
	return 0;
}




