#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b; a<c; a++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define ll long long
//#define ANARAP
#define MOD 1000000007
vector<ll> medios;
ll n,x,pos,ans=1, usados=0;

void bs(ll z){
	ll left=0;
	ll right=n;
	ll mayores=n-x, menores=x-1;
	while(left<right){
		ll middle = (left+right)/2;
		if(middle<=z){
			left=middle+1;
			if(middle!=z){
				ans=(ans%MOD*menores%MOD)%MOD;
				menores--;
				usados++;
			}
		}else{
			right=middle;
			ans=(ans%MOD*mayores%MOD)%MOD;
			mayores--;
			usados++;
		}
	}
}

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll tam;
	cin>>n>>x>>pos;
	
	bs(pos);
	tam=n-usados-1;
	
	vector<ll> fact;
	fact.resize(1001,1);
	forr(i,1,1001) fact[i]=(fact[i-1]%MOD*i%MOD)%MOD;
	
	ans=(fact[tam]%MOD*ans%MOD)%MOD;
	cout<<ans<<"\n";
	
	return 0;
}
