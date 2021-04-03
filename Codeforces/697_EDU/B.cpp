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
		string s;
		cin>>n;
		cin>>s;
		
		ll camba=0, cambb=0;
		forn(j,n){
			if((j%2==0 && s[j]=='0') || (j%2==1 && s[j]=='1')){
				while((j%2==0 && s[j]=='0') || (j%2==1 && s[j]=='1')) j++;
				camba++;
			}
		}
		forn(j,n){
			if((j%2==0 && s[j]=='1') || (j%2==1 && s[j]=='0')){
				while((j%2==0 && s[j]=='1') || (j%2==1 && s[j]=='0')) j++;
				cambb++;
			}
		}
		ll ans=min(cambb,camba);
		cout<<ans<<"\n";
	}
	
	return 0;
}
