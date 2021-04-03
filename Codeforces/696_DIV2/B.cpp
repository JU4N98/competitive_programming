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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<bool> criba(100000,true);
	forr(i,2,100000){
		if(criba[i]) for(int j=i*2;j<100000;j+=i) criba[j]=false;
	}
	
	ll t;
	cin>>t;
	forn(T,t){
		ll d;
		cin>>d;
		ll count=0,ans=1,aux=d+1;
		while(count!=2){
			if(criba[aux]){
				ans*=aux;
				count++;
				aux+=d;
			}else aux++;
		}
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
}

