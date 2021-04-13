#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
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
const int MAXN = 10000100;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int criba[MAXN];
	ll suma[MAXN],ans[MAXN];
	forn(i,MAXN){
		criba[i]=-1;
		ans[i]=-1;
	}
	
	criba[1]=1;
	forr(i,2,MAXN){
		if(criba[i]!=-1) continue;
		criba[i]=i;
		for(ll j=i*i;j<MAXN;j+=i) if(criba[j]==-1) criba[j]=i;
	}
	
	suma[1]=1;
	forr(i,2,MAXN){
		if(criba[i]==i){
			suma[i]=i+1;
		}else{
			ll aux=i;
			suma[i]=1;
			while(aux%criba[i]==0){
				suma[i]=suma[i]*criba[i]+1;
				aux/=criba[i];
			}
			suma[i]*=suma[aux];
		}
	}
	
	
	forr(i,1,MAXN){
		if(suma[i]<MAXN && ans[suma[i]]==-1) ans[suma[i]]=i;
	}
	
	
	ll t;
	cin>>t;
	forn(T,t){
		ll c;
		cin>>c;
		cout<<ans[c]<<"\n";
	}
	
	return 0;
}




