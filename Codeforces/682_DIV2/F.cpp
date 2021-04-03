#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b; a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it=v.begin;it!=v.end();it++)
#define fst first
#define snd second
#define ll long long
#define pb push_back
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		cin>>n;
		forn(j,n) cout<<"1 ";
		cout<<"\n";
	}
	return 0;
}
