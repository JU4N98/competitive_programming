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
		map<ll,ll> m;
		in.resize(n);
		forn(j,n){ 
			cin>>in[j];
			if(m.find(in[j])==m.end()) m[in[j]]=j;
		}
					
		if(m.size()==1){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
			ll comp[2], tam=0;
			for(auto ite=m.begin(); ite!=m.end(); ite++){
				if(tam<2){
					comp[tam]=ite->first;
					tam++;
				}
			}
			cout<<m[comp[0]]+1<<" "<<m[comp[1]]+1<<"\n"; 
			forn(j,n){
				if(j!=m[comp[0]] && j!=m[comp[1]]){
					if(in[j]!=comp[0]) cout<<j+1<<" "<<m[comp[0]]+1<<"\n";
					else cout<<j+1<<" "<<m[comp[1]]+1<<"\n";
				}
			}
		}
		
		
		m.clear();
	}
	
	return 0;
}
