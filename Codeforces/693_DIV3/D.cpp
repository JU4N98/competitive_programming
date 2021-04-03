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
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
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
		vector<ll> num(n),even,odd;
		ll suma=0,sumb=0;
		forn(i,n){
			cin>>num[i];
		}
		sort(num.begin(),num.end());
		ll turn=0;
		dforn(i,n){
			if(num[i]%2==0){
				if(turn%2==0) suma+=num[i];
			}else{
				if(turn%2==1) sumb+=num[i];
			}
			turn++;
		}
		if(suma>sumb){
			cout<<"Alice\n";
		}else if(suma<sumb){
			cout<<"Bob\n";
		}else{
			cout<<"Tie\n";
		}
	}
	
	return 0;
}
