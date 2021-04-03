#include <bits/stdc++.h>
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
	// agregar g++ -DANARAP en compilacion
	#ifdef ANARAP
		freopen("input", "r", stdin);
		//freopen("output","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		ll arr[19],lcm=1;
		forr(i,1,10){
			lcm=(lcm*i)/__gcd((ll) i,lcm);
		}
		forn(i,lcm+1){
			bool sol=true;
			ll aux=n+i,pos=0;
			while(aux!=0){
				arr[pos]=aux%10;
				aux/=10;
				pos++; 
			}
			forn(j,pos) if(arr[j]!=0) if((n+i)%arr[j]!=0) sol=false;
			if(sol){ cout<<n+i<<"\n"; break;}
		}
		
		
	}
	return 0;
}

