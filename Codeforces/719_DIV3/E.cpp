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
		ll n;
		string s;
		cin>>n;
		cin>>s;
		vector<ll> pre(n),suf(n),cantp(n),cants(n);
		ll cant=0;
		forn(i,n){
			cantp[i]=cant;
			if(s[i]=='*'){
				if(i>0) pre[i]+=pre[i-1];
				cant++;
			}else{
				pre[i]=cant;
				if(i>0) pre[i]+=pre[i-1];
			}
		}
		cant=0;
		dforn(i,n){
			cants[i]=cant;
			if(s[i]=='*'){
				if(i<n-1) suf[i]+=suf[i+1];
				cant++;
			}else{
				suf[i]=cant;
				if(i<n-1) suf[i]+=suf[i+1];
			}
		}
		//~ forn(i,n) cout<<pre[i]<<" ";
		//~ cout<<"\n";
		//~ forn(i,n) cout<<suf[i]<<" ";
		//~ cout<<"\n";
		ll ans=LLONG_MAX;
		forn(i,n){
			ll ans2=0;
			if(i>0) ans2+=pre[i-1];
			if(i<n-1) ans2+=suf[i+1];
			if(s[i]!='*'){
				ll mini=LLONG_MAX;
				if(i==0) mini=0;
				else if(i==n-1) mini=0;
				else{
					mini=min(cantp[i],cants[i]);
				}
				ans2+=mini;
			}
			ans=min(ans,ans2); 
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}




