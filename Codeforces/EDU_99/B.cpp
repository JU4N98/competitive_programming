#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it = v.begin(); it!=v.end(); it++)
#define fst first
#define snd second
#define pb push_back
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	set<ll> s;
	map<ll,ll> m;
	ll aux=0;
	
	forr(i,1,2000){
		aux+=i;
		s.insert(aux);
		m.insert({aux,i});
	}
	
	forn(i,t){
		ll n;
		cin>>n;
		auto ite = s.lower_bound(n);
		ll val = m[*ite];
		
		if((*ite-n)==1) cout<<val+1<<"\n";
		else cout<<val<<"\n";
		
	}
	
	
	return 0;
}
