#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b;a<c;a++)
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
		forn(j,n) mat[j].resize(n);
		forn(j,n) forn(k,n){
			char aux;
			cin>>aux;
			mat[j][k]=aux-'0';
		}
		
		ll cant1 = mat[0][1] + mat[1][0];
		ll cant2 = mat[n-1][n-2] + mat[n-2][n-1];
		if(cant1>cant2){
			if(cant1==1){
				if(mat[0][1]==0){
					cout<<1<<"\n";
					cout<<1<<" "<<2<<"\n";
				}else if(mat[1][0]==0){
					cout<<1<<"\n";
					cout<<2<<" "<<1<<"\n";
				}
			}else{
				if(mat[n-1][n-2]==1){
					cout<<1<<"\n";
					cout<<n<<" "<<n-1<<"\n";
				}else if(mat[n-2][n-1]==1) {
					cout<<1<<"\n";
					cout<<n-1<<" "<<n<<"\n";
				}else{
					cout<<0<<"\n";
				}
			}
		}else if(cant1<cant2){
			if(cant2==1){
				if(mat[n-1][n-2]==0){
					cout<<1<<"\n";
					cout<<n<<" "<<n-1<<"\n";
				}else if(mat[n-2][n-1]==0) {
					cout<<1<<"\n";
					cout<<n-1<<" "<<n<<"\n";
				}
			}else{
				if(mat[0][1]==1){
					cout<<1<<"\n";
					cout<<1<<" "<<2<<"\n";
				}else if(mat[1][0]==1){
					cout<<1<<"\n";
					cout<<2<<" "<<1<<"\n";
				}else{
					cout<<0<<"\n";
				}
			}
		}else{
			if(cant1==1){
				cout<<2<<"\n";
				if(mat[0][1]==0){
					cout<<1<<" "<<2<<"\n";
				}else if(mat[1][0]==0){
					cout<<2<<" "<<1<<"\n";
				}
				if(mat[n-1][n-2]==1){
					cout<<n<<" "<<n-1<<"\n";
				}else if(mat[n-2][n-1]==1) {
					cout<<n-1<<" "<<n<<"\n";
				}
			}else{
				cout<<2<<"\n";
				cout<<n<<" "<<n-1<<"\n";
				cout<<n-1<<" "<<n<<"\n";
			}
		}
		
		
		
		mat.clear();
	} 
	
	
	return 0;
}
