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
		ll aux:
		vector<ll> dig,vlcm;
		while(aux!=0){
			dig.pb(aux%10);
			aux/=10;
		}
		ll gcd=0,lcm=1;
		forr(i,,dig.size()){
			if(dig[i]!=0){
				if(lcm==1){
					lcm = dig[i];
					gcd = dig[i];
				}else{
					gcd = __gcd(dig[i],lcm);
					lcm = (lcm*dig[i])/gcd;
				}
			}
			vlcm.pb(lcm);
		}
		reverse(vlcm.begin());
	}
	
	
	return 0;
}
