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
		string r,b;
		cin>>r>>b;
		ll cantr=0, cantb=0;
		forn(i,n){
			if(r[i]-'0'>b[i]-'0'){
				cantr++;
			}else if(r[i]-'0'<b[i]-'0'){
				cantb++;
			}
		}
		if(cantb<cantr){
			cout<<"RED\n";
		}else if(cantb>cantr){
			cout<<"BLUE\n";
		}else{
			cout<<"EQUAL\n";
		}
	}
	
	return 0;
}
