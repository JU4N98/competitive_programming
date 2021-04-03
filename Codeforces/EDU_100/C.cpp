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
	forn(i,t){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> ope;
		forn(j,n){
			ll ti, xi;
			cin>>ti>>xi;
			pair<ll,ll> p = {ti,xi};
			ope.pb(p);
		}
		
		ll ans=0, ti=0, tf=0, xi=0, xf=0;
		forn(j,n){
			//cout<<ope[j].fst<<" "<<ope[j].snd<<endl;
			if(ope[j].fst>=tf){
				ti=ope[j].fst;
				tf=ope[j].fst+abs(ope[j].snd-xf);
				xi=xf;
				xf=ope[j].snd;
				if(j+1<n){
					//cout<<"a"<<endl;
					if(ope[j+1].fst>=tf) ans++;
				}else{
					//cout<<"b"<<endl;
					ans++;
				}
			}else{
				ll ti1=ope[j].fst, tf1, xf1=ope[j].snd,xi1;
				if(tf!=ti){
					xi1=((xf-xi)/(tf-ti))*(ti1-ti)+xi;
				}else{
					xi1=xi;
				}
				//dbg(xf)
				//dbg(xi1)
				//dbg(xf1)
				if(min(xi1,xf)<=xf1 && xf1<=max(xi1,xf)){
					//cout<<"c"<<endl;
					tf1=ti1+abs(xf1-xi1);
					if(j+1<n){
						//cout<<"d"<<endl;
						if(ope[j+1].fst>=tf1) ans++;
					}else{
						//cout<<"e"<<endl;
						ans++;
					}
				}else{
					//cout<<"f"<<endl;
				}
			}
			//cout<<"ANS "<<ans<<endl;
		}
		//cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA "<<ans<<"\n";
		cout<<ans<<"\n";
		ope.clear();
	}
	
	
	return 0;
}
