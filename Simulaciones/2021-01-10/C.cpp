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
	 
	 ll a,b;
	 cin>>a>>b;
	 
	 ll posa=0;
	 while(calc(posa*2+1)<a) posa++;
	 ll posb=0;
	 while(calc(posb*2+1)<b) posb++;
	 
	 ll xa=16001-posa,ya=16001+posa, vala=calc(posa*2+1);
	 forn(i,posa*2){
		 if(vala==a) break;
		 else{ vala--; ya--;}
	 }
	 forn(i,posa*2){
		 if(vala==a) break;
		 else{ vala--; xa++;}
	 }
	 forn(i,posa*2){
		 if(vala==a) break;
		 else{ vala--; ya++;}
	 }
	 forn(i,posa*2-1){
		 if(vala==a) break;
		 else{ vala--; xa--;}
	 }
	 
	 ll xb=16001-posb,yb=16001+posb, valb=calc(posb*2+1);
	 forn(i,posb*2){
		 if(valb==b) break;
		 else{ valb--; yb--;}
	 }
	 forn(i,posb*2){
		 if(valb==b) break;
		 else{ valb--; xb++;}
	 }
	 forn(i,posb*2){
		 if(valb==b) break;
		 else{ valb--; yb++;}
	 }
	 forn(i,posb*2-1){
		 if(valb==b) break;
		 else{ valb--; xb--;}
	 }
	 
	 cout<<abs(xa-xb)+abs(ya-yb)<<"\n";
	 
	 return 0;
}


