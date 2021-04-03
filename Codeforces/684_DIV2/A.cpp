#include<bits/stdc++.h>
using namespace std;

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
	forn(i,t){
		ll n,c0,c1,h;
		string s;
		cin>>n>>c0>>c1>>h;
		cin>>s;
		ll sum=0;
		if(c1>c0+h){
			forn(j,n) if(s[j]=='1'){ s[j]='0'; sum++;}
		}
		if(c0>c1+h){
			forn(j,n) if(s[j]=='0'){ s[j]='1'; sum++;} 
		}
		ll ans=0;
		forn(j,n) if(s[j]=='0') ans+=c0; else ans+=c1;
		ans+=sum*h;
		cout<<ans<<"\n"; 
	}
	
	
	return 0;
}
