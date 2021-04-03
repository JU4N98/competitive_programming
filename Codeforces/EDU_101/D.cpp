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
		ll n;
		cin>>n;
		if(n<=16){
			cout<<n+1<<"\n";
			forr(i,1,n){
				if(i!=1 && i!=2){
					cout<<i<<" "<<n<<"\n";
				}
			}
			forn(i,4) cout<<n<<" "<<2<<"\n";
		}else{
			cout<<n+4<<"\n";
			forr(i,1,n){
				if(i!=1 && i!=2 && i!=4 && i!=16){
					cout<<i<<" "<<n<<"\n";
				}
			}
			cout<<n<<" "<<16<<"\n";
			cout<<n<<" "<<16<<"\n";
			cout<<n<<" "<<16<<"\n";
			cout<<n<<" "<<16<<"\n";
			cout<<n<<" "<<16<<"\n";
			
			cout<<16<<" "<<4<<"\n";
			cout<<16<<" "<<4<<"\n";
			
			cout<<4<<" "<<2<<"\n";
			cout<<4<<" "<<2<<"\n";
			
		}
	}
	
	return 0;
}

