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

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		cin>>n;
		vector<ll> in;
		in.resize(n);
		ll sump=0,sumn=0;
		forn(j,n){
			cin>>in[j];
			if(in[j]<0) sumn+=in[j]; else sump+=in[j];
		}
		if(abs(sumn)==sump){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
			if(abs(sumn)>sump){
				sort(in.begin(),in.end());
			}else{
				sort(in.begin(),in.end(),greater<ll>());
			}
			forn(j,n) cout<<in[j]<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}
