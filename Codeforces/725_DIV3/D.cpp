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
	
	bool criba[40000];
	forn(i,40000) criba[i]=true;
	forr(i,2,40000){
		if(criba[i]) for(int j=i+i;j<40000;j+=i) criba[j]=false;
	}
	vector<ll> primos;
	forr(i,2,40000) if(criba[i]) primos.pb(i);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll a,b,k;
		cin>>a>>b>>k;
		if((max(a,b)%min(a,b)!=0 || a==b)&& k<2) cout<<"NO\n";
		else{
			map<ll,ll> fa,fb;
			forn(i,sz(primos)) while(a%primos[i]==0) fa[primos[i]]++,a/=primos[i];
			if(a>1) fa[a]++;
			forn(i,sz(primos)) while(b%primos[i]==0) fb[primos[i]]++,b/=primos[i];
			if(b>1) fb[b]++;
			ll sum=0;
			forall(it,fa) sum+=it->snd;
			forall(it,fb) sum+=it->snd;
			if(sum>=k) cout<<"YES\n"; else cout<<"NO\n";
		}
	}
	
	return 0;
}




