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
	forn(T,t){
		ll n;
		cin>>n;
		string s;
		cin>>s;
		ll j = n-1, count=0;	
		while(j>-1 && s[j]==')'){ count++; j--;}
		if(count>n-count) cout<<"Yes\n"; else cout<<"No\n";  
	}
	
	
	return 0;
}
