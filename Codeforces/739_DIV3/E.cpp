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
	
	ll t;cin>>t;
	forn(T,t){
		string s; cin>>s;
		
		vector<int> car(26);
		int dif=0,dif2;
		forn(i,sz(s)){
			car[s[i]-'a']++;
			if(car[s[i]-'a']==1) dif++;
		}
		dif2=dif;
		
		bool ok=true;
		vector<char> ans;
		vector<bool> pres(26,false);
		vector<int> cant(26);
		dforn(j,sz(s)){
			if(!pres[s[j]-'a']){
				ans.pb(s[j]);
				pres[s[j]-'a']=true;
				if(car[s[j]-'a']%dif!=0) ok=false;
				cant[s[j]-'a']=car[s[j]-'a']/dif;
				dif--;
			}
		}
		reverse(ans.begin(),ans.end());
		
		ll r=0; forn(i,sz(cant)) r+=cant[i];
		
		string ansi="";
		forn(i,r) ansi+=s[i];
		vector<bool> p1(26,true);
		
		ll pos=0;
		forn(i,dif2){
			//~ cout<<r<<endl;
			ll posa=0;
			forn(j,r){
				while(posa<sz(ansi) && !p1[ansi[posa]-'a']) posa++;
				//~ cout<<"	s["<<pos<<"]="<<s[pos]<<" ansi["<<posa<<"]"<<ansi[posa]<<"\n";
				if(s[pos]!=ansi[posa]) ok=false;
				pos++;
				posa++;
			}
			p1[ans[i]-'a']=false;
			r-=cant[ans[i]-'a'];
			//~ cout<<ok<<endl;
		}
		
		if(ok){
			cout<<ansi;
			cout<<" ";
			forn(i,sz(ans)) cout<<ans[i];
			cout<<"\n";
		}else{
			cout<<"-1\n";
		}
	}
	
	return 0;
}




