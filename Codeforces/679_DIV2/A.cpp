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
		vector<ll> a,b;
		a.resize(n);
		forn(j,n) cin>>a[j];
			
		b=a;
		b.resize(n);
		vector<bool> aux;
		aux.resize(n,false);
		forn(j,n){
			if(!aux[j]){
				if(a[j]<0 && a[n-j-1]<0){
					b[j]=a[n-j-1];
					b[n-j-1]=abs(a[j]);
				}else if(a[j]<0 && a[n-1-j]>0){
					b[j]=a[n-j-1];
					b[n-j-1]=abs(a[j]);
				}else if(a[j]>0 && a[n-j-1]<0){
					b[j]=abs(a[n-j-1]);
					b[n-j-1]=a[j];
				}else {
					b[j]=a[n-j-1];
					b[n-j-1]=-a[j];
				}
				aux[j]=true;
				aux[n-j-1]=true;
			}
		}
		forn(j,n) cout<<b[j]<<" ";
		cout<<"\n";
	}
	
	return 0;
}
