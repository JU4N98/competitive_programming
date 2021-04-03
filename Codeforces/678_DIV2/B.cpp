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
		vector<vector<ll>> mat;
		mat.resize(n);
		forn(j,n) mat[j].resize(n,0);
		forn(j,n){
			if(j!=n-1){
				mat[j][j+1]=1;
				mat[j+1][j]=1;
			}
			mat[j][j]=1;
		} 
		forn(j,n){
			forn(k,n){
				cout<<mat[j][k]<<" ";
			}
			cout<<endl;
		}
		mat.clear();
	}
	
	
	return 0;
}
