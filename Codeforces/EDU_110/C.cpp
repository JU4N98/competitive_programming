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
typedef pair<ll,ll> ii;

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
		//~ cout<<"T "<<T<<endl;
		string s;
		cin>>s;
		ll curr=0,preg=0,tip=-1;
		ll ans=0,aux=0;
		forn(i,sz(s)){
			if(tip==-1 || (s[i]=='1' && tip==1) || (s[i]=='0' && tip==0) || s[i]=='?'){
				if(tip==0) tip=1; else if(tip==1) tip=0;
				if(tip==-1){
					if(s[i]=='0') tip=1;
					else if(s[i]=='1') tip=0;
				}
				curr++;
				if(s[i]=='?') preg++;
				else preg=0;
			}else{
				ans+=(curr*(curr-1))/2;
				ans-=aux;
				curr=preg;
				aux=(preg*(preg-1))/2;
				preg=0;
				curr++;
			}
			//~ cout<<"I="<<i<<": "<<curr<<" "<<preg<<"\n";
			//~ cout<<ans<<endl;
		}
		ans+=(curr*(curr-1))/2-aux;
		cout<<ans + sz(s) <<"\n";
	}
	
	return 0;
}




