#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define pb(i) push_back(i)
#define fst first
#define snd second
#define ll long long
#define ANARAP
#define MOD 998244353
ll fact[400000];


int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	ll n,sum=0;
	vector<ll> a;
	cin>>n;
	a.resize(2*n);
	forn(i,2*n){
		cin>>a[i];
		sum+=a[i];
	}
	
	fact[0]=1;
	forr(i,1,200000) fact[i]=(fact[i-1]*i)%MOD; 
	ll factor=1;
	forr(i,n+1,2*n) factor=(factor*i)%MOD;
	ll ans=0;
	forn(i,n){
		ans=(ans%MOD+(abs(a[i]*factor-(sum-a[i])*factor))%MOD)%MOD;
	}
	cout<<ans%MOD<<"\n";
	
} 
