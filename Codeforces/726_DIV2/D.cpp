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
#define ANARAP

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
	
	bool criba[50000];
	forn(i,50000) criba[i]=true;
	forr(i,2,50000){
		if(criba[i]){
			for(int j=i+i;j<50000;j+=i) criba[i]=false;
		}
	}
	vector<ll> primos;
	forr(i,2,50000) primos.pb(i);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,naux;
		cin>>n;
		naux=n;
		ll cantf=0;
		forn(i,sz(primos)) while(n%primos[i]==0){n/=primos[i];cantf++;}
		if(n!=1) cantf++;
		if(naux==1) cout<<"Bob\n";
		else{
			cout<<cantf<<endl;
			if(cantf==1) cout<<"Bob\n";
			else cout<<"Alice\n";
		}
	}
	
	
	return 0;
}




