#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it = v.begin(); it!=v.end(); it++)
#define fst first
#define snd second
#define pb push_back
#define ll long long
#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		vector<ll> dig;
		ll aux=n;
		do { dig.pb(aux%10); aux/=10;} while(aux/10!=0);
		ll gcd = 0, prod=1, lcm=1;
		forr(i,1,dig.size()){
			if(gcd==0) gcd=dig[i];
			if(dig[i]!=0){
				gcd = __gcd(gcd,dig[i]);
				lcm = abs(lcm*dig[i])/gcd;
			}
		}
		cout<<lcm<<endl;
		cout<<n+(lcm-(n%lcm))<<"\n";
		dig.clear();
	}
	
	
	
	return 0;
}
