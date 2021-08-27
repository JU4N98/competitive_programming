#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(ll i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<vector<ll>> pot;
	ll pote=1;
	forr(i,1,64){
		ll aux=pote;
		vector<ll> vec;
		while(aux>0){
			vec.pb(aux%10);
			aux/=10;
		}
		reverse(vec.begin(),vec.end());
		pot.pb(vec);
		pote*=2LL;
	}
	
	ll t; cin>>t;
	forn(T,t){
		ll n; cin>>n;
		vector<ll> num;
		while(n>0){
			num.pb(n%10);
			n/=10;
		}
		reverse(num.begin(),num.end());
		ll ans=sz(num)+1;
		//cout<<"a"<<endl;
		forn(i,63){
			//cout<<i<<endl;
			int posn=0,posp=0;
			while(posn<sz(num) && posp<sz(pot[i])){
				if(num[posn]==pot[i][posp]){
					posp++;
				}
				posn++;
			}
			ll cost = sz(num)-posp+sz(pot[i])-posp;
			ans=min(cost,ans);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}




