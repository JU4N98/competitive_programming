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
	forn(i,t){
		string s;
		cin>>s;
		ll canta=0, cantb=0,ans=0;
		forn(j,s.size()){
			
			if(s[j]=='[') canta++;
			if(s[j]=='(') cantb++;
			if(s[j]==']' && canta>0){canta--; ans++;}
			if(s[j]==')' && cantb>0){cantb--; ans++;}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
