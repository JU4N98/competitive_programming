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
		ll n,m;
		cin>>n>>m;
		vector<vector<ll>> fil,col;
		
		fil.resize(n);
		col.resize(m);
		forn(j,n) fil[j].resize(m);
		forn(j,m) col[j].resize(n);
		forn(j,n) forn(k,m) cin>>fil[j][k];
		forn(j,m) forn(k,n) cin>>col[j][k];
		
		
		vector<ll> ajus;
		ajus.resize(n);
		forn(h,n){
			bool sol=false;
			forn(l,m){
				forn(k,n){
					if(col[l][k]==fil[h][0]){
						ajus[k]=h;
						sol=true;
						break;
					}
				}
				if(sol) break;
			}
		}
		
		vector<vector<ll>> ans;
		ans.resize(n);
		forn(j,n){
			forn(k,m){
				cout<<fil[ajus[j]][k]<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}
