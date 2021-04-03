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
		ll x,y;
		cin>>x>>y;
		ll c[6];
		forn(j,6) cin>>c[j];
		ll alt1=LLONG_MAX, alt2=LLONG_MAX,alt3=LLONG_MAX;
		if(x<0){
			if(y<0){
				alt1=c[2]*abs(x)+c[4]*abs(y);
				(x<y)? alt2=abs(x)*c[3]+(y-x)*c[1] : alt2=abs(x)*c[3]+(x-y)*c[4];
				(x<y)? alt3=abs(y)*c[3]+(y-x)*c[2] : alt3=abs(y)*c[3]+(x-y)*c[5]; 
			}else if(y>0){
				alt1=c[2]*abs(x)+c[1]*abs(y);
				alt2=-x*c[3]+(y-x)*c[1];
				alt3=y*c[0]+(y-x)*c[2];
			}else if(y==0){
				alt1=abs(x)*c[2];
				alt2=abs(x)*c[1]+abs(x)*c[3];
			}
			
		}else if(x>0){
			if(y<0){
				alt1=c[5]*abs(x)+c[4]*abs(y);
				alt2=c[0]*abs(x)+(x-y)*c[4];
				alt3=c[3]*abs(y)+(x-y)*c[5];
			}else if(y>0){
				alt1=c[5]*abs(x)+c[1]*abs(y);
				(x>y)? alt2=c[0]*x+(x-y)*c[4]: alt2=c[0]*x+(y-x)*c[1];
				(x>y)? alt3=c[0]*y+abs(x-y)*c[5]: alt3=c[0]*y+(y-x)*c[2];
			}else if(y==0){
				alt1=abs(x)*c[5];
				alt2=abs(x)*c[4]+abs(x)*c[0];
			}
		}else{
			if(y<0){
				alt1=c[4]*abs(y);
				alt2=abs(y)*c[5]+abs(y)*c[3];
			}else if(y>0){
				alt1=c[1]*abs(y);
				alt2=abs(y)*c[0]+abs(y)*c[2];
			}else if(y==0){
				alt1=0;
			}
		}
		cout<<min(min(alt1,alt2),alt3)<<endl;
	}
	
	return 0;
}
