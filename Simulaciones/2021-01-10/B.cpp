#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef ANARAP
#else
#endif

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

ll calc(ll n){
	if(n==1) return 1;
	else return (n-1)*(n-1)+n*2+(n-2)*2;
}

int main(){
	#ifdef ANARAP
	 freopen("input.in", "r", stdin);
	 #endif
	 
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 
	 ll n,a,b,c,subprojects=0;
	 cin>>n>>a>>b>>c;
	 vector<ll> cantprojects(n);
	 vector<queue<pair<ll,pair<ll,ll>>>> projects(n);
	 forn(i,n){
		 cin>>cantprojects[i];
		 subprojects+=cantprojects[i];
	 }
	 forn(i,n){
		 forn(j,cantprojects[i]){
			 string s;
			 cin>>s;
			 stringstream ss(s);
			 ll t,p,bitmask=0;
			 ss>>t>>p;
			 while(ss>>s){
				 if(s=="Camera") bitmask|=1;
				 if(s=="Camcorder") bitmask|=2;
				 if(s=="Computer") bitmask|=4;
			 }
			 cin>>t>>p;
			 projects[i].push({p,{t,bitmask}});
		 }
	 }
	 vector<priority_queue<pair<ll,pair<ll,ll>>>> prioridades(8);
	 forn(i,n){
		 pair<ll,pair<ll,ll>> pp = projects[i].front();
		 projects[i].pop();
		 prioridades[pp.snd.snd].push({pp.fst,{pp.snd.fst,i}});
	 }
	 ll tiempo=0;
	 vector<ll> ans(n);
	 vector<pair<ll,ll>> posibles;
	 set<pair<ll,pair<ll,ll>>> ejecucion;
	 while(subprojects!=0){
		 auto it = ejecucion.begin();
		 if(it!=ejecucion.end()){
			tiempo= (*it).fst;
			pair<ll,pair<ll,ll>> pp = projects[(*it).snd.fst].front();
			projects[(*it).snd.fst].pop();
			if(projects[(*it).snd.fst].empty()==1) ans[(*it).snd.fst]=tiempo;
			prioridades[pp.snd.snd].push({pp.fst,{pp.snd.fst,(*it).snd.fst}});
			ll k = (*it).snd.snd;
			a+=(k&1);
			b+=((k>>1)&1);
			c+=((k>>2)&1);
			ejecucion.erase(it);
			subprojects--;
			}
		 it=ejecucion.begin();
		 while(it!=ejecucion.end() 
		 && (*it).fst==tiempo){
			pair<ll,pair<ll,ll>> pp = projects[(*it).snd.fst].front();
			projects[(*it).snd.fst].pop();
			if(projects[(*it).snd.fst].empty()==1) ans[(*it).snd.fst]=tiempo;
			prioridades[pp.snd.snd].push({pp.fst,{pp.snd.fst,(*it).snd.fst}});
			ll k = (*it).snd.snd;
			a+=(k&1);
			b+=((k>>1)&1);
			c+=((k>>2)&1);
			ejecucion.erase(it);
			ejecucion.erase(it);
			subprojects--;
		 }
		 forn(i,8){
			 if((!(i&1) || a>0) 
			 && (!((i>>1)&1) || b>0)
			 && (!((i>>2)&1) || c>0)){
				 posibles.pb({prioridades[i].top().fst,i});
			 }
			 sort(posibles.begin(),posibles.end());
			 dforn(j,posibles.size()){
				 ll k=posibles[j].snd;
				 if((!(k&1) || a>0) 
				 && (!((k>>1)&1) || b>0)
				 && (!((k>>2)&1) || c>0)){
					 a-=(k&1);
					 b-=((k>>1)&1);
					 c-=((k>>2)&1);
					 pair<ll,pair<ll,ll>> pp =prioridades[k].top();
					 prioridades[k].pop();
					 ejecucion.insert({tiempo+pp.snd.fst,{pp.snd.snd,k}});
				 }
			 }
		 }
		 
	 }
	 forn(i,n) cout<<ans[i]<<" ";
	 cout<<"\n";
	 
	 return 0;
}


