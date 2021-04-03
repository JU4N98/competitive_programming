#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b; a<c; a++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define ll long long
#define ANARAP



int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll n,k;
	vector<ll> a;
	set<ll> s;
	
	cin>>n>>k;
	a.resize(n);
	forn(i,n) cin>>a[i];
	forn(i,k){
		ll aux;
		cin>>aux;
		s.insert(k);
	}
	
	
	return 0;
}
