#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i<n; i++)
using namespace std;
#define MAXP 100000
int criba[MAXP+1];
const long long mod = 1'000'000'009;

long long pot(long long a, long long e){
	long long ans = 1, pow = a;
	while(e>0){
		if(e%2 == 1){	
			ans = (ans * pow)%mod;
		}
		pow = (pow * pow)%mod;
		e/=2;
	} 
	return ans;
}

void crearCriba(){
	int w[] = {4,2,4,2,4,6,2,6};
	for(int p=25;p<=MAXP; p+=10) criba[p]=5;
	for(int p=9;p<=MAXP; p+=6) criba[p]=3;
	for(int p=4;p<=MAXP; p+=2) criba[p]=2;
	for(int p=7,  cur=0; p*p<=MAXP; p+=w[cur++&7]) if(!criba[p])
	for(int j = p*p; j<=MAXP; j+=(p<<1)) if(!criba[j]) criba[j] =p;
}
vector <int> primos;
void buscarPrimos(){
	crearCriba();
	for(int i = 2; i<MAXP+1;i++) if(!criba[i]) primos.push_back(i);
}
void fact(long long n, map <long long, long long > &f){
	for(auto p: primos){
		while(!(n%p)){
			f[p]++;
			n/=p;
		}
	}
	if(n>1) f[n]++;
}

int main() {
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	buscarPrimos();
	
	long long k,d,m;
	cin>>k>>d>>m;
	
	map <long long,long long> plcm;
	map <long long, long long> pgcd;
	
	fact(d,pgcd);
	fact(m,plcm);
	
	if(m%d!=0){
		cout<<0<<'\n';
		return 0;
	} 
	
	long long ans = 1;
	for(auto e: plcm){
		long long a = pgcd[e.first], b = e.second;
		
		if(a!=b){
			long long fact = pot(b-a+1,k);
			fact = ((fact - 2LL*pot(b-a,k))%mod+mod)%mod;
			fact = ((fact + pot(b-a-1LL,k))%mod+mod)%mod;
			ans = (ans * fact)%mod;
		}
	}
	
	cout<<ans<<'\n';
	
	
	
	return 0;
}












 
