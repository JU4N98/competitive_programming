#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll x,y,x1,y1;
		cin>>x>>y>>x1>>y1;
		if(x==x1 && y==y1){
			cout<<0<<"\n";
		}else if(x==x1){
			cout<<abs(y-y1)<<"\n";
		}else if(y==y1){
			cout<<abs(x-x1)<<"\n";
		}else{
			cout<<abs(y-y1)+abs(x-x1)+2<<"\n";
		}
	}
	
	return 0;
} 
