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
#define MOD 1000000007
#define MAXP 1000000

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
int criba[MAXP+1];

ll mulMod(ll a, ll b, ll m=MOD){
	ll x=0,y=a%m;
	while(b>0){
		if(b%2==1) x=(x+y)%m;
		y=(y*2)%m;
		b/=2;
	}
	return x%m;
}

ll expMod(ll b, ll e, ll m=MOD){
	if(!e) return 1;
	ll q=expMod(b,e/2,m);
	q=mulMod(q,q,m);
	return e%2? mulMod(b,q,m) : q;
}

bool es_primo_prob(ll n, int a){
	if(n==a) return true;
	ll s=0,d=n-1;
	while(d%2==0) s++,d/=2;
	ll x=expMod(a,d,n);
	if((x==1) || (x+1==n)) return true;
	forn(i,s-1){
		x=mulMod(x,x,n);
		if(x==1) return false;
		if(x+1==n) return true;
	}
	return false;
}

bool rabin(ll n){
	if(n==1) return false;
	const int ar[]={2,3,5,7,11,13,17,19,23};
	forn(j,9) if(!es_primo_prob(n,ar[j])) return false;
	return true;
}


void crearCriba(){
	int w[]={4,2,4,2,4,6,2,6};
	for(int p=25;p<=MAXP;p+=10) criba[p]=5;
	for(int p=9;p<=MAXP;p+=6) criba[p]=3;
	for(int p=4;p<=MAXP;p+=2) criba[p]=2;
	for(int p=7,cur=0;p*p<=MAXP;p+=w[cur++&7]) if(!criba[p])
	for(int j=p*p;j<=MAXP;j+=(p<<1)) if(!criba[j]) criba[j]=p;
}

vector<ll> primos;
void buscarPrimos()
{
	crearCriba();
	forr (i,2,MAXP+1) if (!criba[i]) primos.push_back(i);
}

void fact2(ll n,map<ll,ll> &f){
	while(criba[n]){
		f[criba[n]]++;
		n/=criba[n];
	}
	if(n>1) f[n]++;
}

ll calc(map<ll,ll> &m){
	ll mult=1LL;
	forall(it,m) mult*=(it->snd+1);
	ll ans=1LL;
	forall(it,m){
		ans*=pow(it->fst,(it->snd*mult)/2);
	}
	return ans;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	crearCriba();
	map<ll,ll> s;
	s[1LL]=1LL;
	forr(i,2,1000000){
		map<ll,ll> m;
		fact2(i,m);
		if(i==410) cout<<calc(m)<<endl;
		s[calc(m)]=i;
	}
	ll m;
	cin>>m;
	ll auxm = m;
	buscarPrimos();
	ll primorandom = -1;
	forall(it, primos){
		while(auxm%*it == 0) {
			auxm/=*it;
			primorandom = *it;
		}
	}
	if(auxm!=1){
		if(primorandom == -1) cout << auxm << '\n';
		else cout << auxm*primorandom << '\n';
	}
	else if(s.find(m)!=s.end()){
		cout<<s[m]<<endl;
	}else{
		cout<<-1LL<<endl;
	}
	
	return 0;
}




