#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b; a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define snd second
#define fst first
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
		ll n,k,in;
		cin>>n>>k;
		vector<pair<ll,ll>> piso(n);
		vector<ll> inicio(n,-1);
		
		forn(i,n){
			cin>>in;
			piso[i]={in,i};
		}
		inicio[0]=piso[0].fst;
		inicio[n-1]=piso[n-1].fst;
		
		sort(piso.begin(),piso.end());
		
		bool sol=true;
		if(n==2){
			if(abs(inicio[1]-inicio[0])>=k) sol=false;
		}
		for(int i=n-1;i>-1;i--){
			ll pos=piso[i].snd;
			ll base=piso[i].fst;
			if(inicio[pos]==-1){
				if(inicio[pos-1]==-1 && inicio[pos+1]==-1){
					inicio[pos]=base;
				}else if(inicio[pos-1]!=-1 && inicio[pos+1]==-1){
					if(pos!=1) inicio[pos]=max(base,inicio[pos-1]-(k-1));
					else{
						if(inicio[pos-1]>=base){
							inicio[pos]=max(base,inicio[pos-1]-(k-1));
						}else if(k+inicio[pos-1]<=base) sol =false;
						else inicio[pos]=base;
					}
				}else if(inicio[pos-1]==-1 && inicio[pos+1]!=-1){
					if(pos!=n-2) inicio[pos]=max(base,inicio[pos+1]-(k-1));
					else{
						if(inicio[pos+1]>=base) inicio[pos]=max(base,inicio[pos+1]-(k-1));
						else if(k+inicio[pos+1]<= base) sol =false;
						else inicio[pos]=base;
					}
				}else{
					ll maxi=max(inicio[pos-1],inicio[pos+1]), mini=min(inicio[pos-1],inicio[pos+1]);
					inicio[pos]=max(maxi-(k-1),base);
					mini+=k;
					if(mini<=inicio[pos]) sol=false;
				}
				if(inicio[pos]>base+k-1) sol=false;
			}
		}
		
		if(sol) cout<<"YES\n"; else cout<<"NO\n";
		piso.clear();
		inicio.clear();
	}
	
	return 0;
}

