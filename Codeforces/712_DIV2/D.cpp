#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	
	ll n;
	cin>>n;
	ii p1={0,0},p2={0,1};
	bool segunda1=false, segunda2=false;
	forn(i,n*n){
		ll color;
		cin>>color;
		if(segunda1 || segunda2){
			if(color==1 || color==2){
				if(segunda2){
					if(color==1) cout<<2<<" "<<p1.fst+1<<" "<<p1.snd+1<<endl;
					else cout<<1<<" "<<p1.fst+1<<" "<<p1.snd+1<<endl;
					do{
						p1.snd++;
						p1.fst+=p1.snd/n;
						p1.snd%=n;
					}while((p1.fst+p1.snd)%2!=0);
				}else{
					cout<<3<<" "<<p2.fst+1<<" "<<p2.snd+1<<endl;
					do{
						p2.snd++;
						p2.fst+=p2.snd/n;
						p2.snd%=n;
					}while((p2.fst+p2.snd)%2!=1);
				}
			}else{
				if(segunda1){
					cout<<2<<" "<<p2.fst+1<<" "<<p2.snd+1<<endl;
					do{
						p2.snd++;
						p2.fst+=p2.snd/n;
						p2.snd%=n;
					}while((p2.fst+p2.snd)%2!=1);
				}else{
					cout<<1<<" "<<p1.fst+1<<" "<<p1.snd+1<<endl;
					do{
						p1.snd++;
						p1.fst+=p1.snd/n;
						p1.snd%=n;
					}while((p1.fst+p1.snd)%2!=0);
				}
				
			}
		}else{
			if(color==1 || color==2){
				cout<<3<<" "<<p2.fst+1<<" "<<p2.snd+1<<endl;
				do{
					p2.snd++;
					p2.fst+=p2.snd/n;
					p2.snd%=n;
				}while((p2.fst+p2.snd)%2!=1);
			}else{
				cout<<1<<" "<<p1.fst+1<<" "<<p1.snd+1<<endl;
				do{
					p1.snd++;
					p1.fst+=p1.snd/n;
					p1.snd%=n;
				}while((p1.fst+p1.snd)%2!=0);
			}
			if(p2.fst>n-1) segunda2=true;
			if(p1.fst>n-1) segunda1=true;
		}
		
		
	}
	
	return 0;
}




