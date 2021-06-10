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

#define MAXP 1000001 
int criba[MAXP+1];

void crearCriba(){
	int w[] = {4,2,4,2,4,6,2,6};
	for(int p=25;p<=MAXP;p+=10) criba[p]=5;
	for(int p=9;p<=MAXP;p+=6) criba[p]=3;
	for(int p=4;p<=MAXP;p+=2) criba[p]=2;
	for(int p=7,cur=0;p*p<=MAXP;p+=w[cur++&7]) if (!criba[p])
	for(int j=p*p;j<=MAXP;j+=(p<<1)) if(!criba[j]) criba[j]=p;
}

void fact2(ll n,map<ll,ll> &f){ 
	while (criba[n])
	{
		f[criba[n]]++;
		n/=criba[n];
	}
	if(n>1) f[n]++;
}

void divisores(map<ll,ll> &f,vector<ll> &divs,map<ll,ll>::iterator it,ll n=1){
	if(it==f.begin()) divs.clear();
	if(it==f.end()){
		divs.pb(n);
		return;
	}
	ll p=it->fst, k=it->snd; ++it;
	forn(_, k+1) divisores(f, divs, it, n), n*=p;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	map<ll,ll> f;
	crearCriba();
	fact2(n,f);
	vector<ll> div;
	divisores(f,div,f.begin(),1LL);
	ll ans=LLONG_MAX;
	forn(i,sz(div)){
		ll act=n/div[i];
		forn(j,sz(div)){
			if(act%div[j]==0){
				ll a=div[i],b=div[j],c=act/div[j];
				ans=min(a*b*2+b*c*2+a*c*2,ans);
			}
		}
	}
	cout<<ans<<endl;
	
	
	return 0;
}




