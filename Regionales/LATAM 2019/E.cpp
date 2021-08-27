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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

ll gauss(ll n){
	if(n<0) return 0;
	return (n*(n+1))/2;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string cake; cin>>cake;
	ll s; cin>>s;
	ll ans = s*sz(cake);
	ll ini=-1;
	forn(i,sz(cake)) if(ini==-1 && cake[i]=='E') ini=i;
	if(ini==-1){
		cout<<"0\n";
	}else{
		//~ cout<<ans<<endl;
		ll cant=0;
		forn(i,sz(cake)){
			if(cake[(i+ini)%sz(cake)]=='E'){
				//~ cout<<cant<<endl;
				//~ cout<<gauss(cant)<<" "<<gauss(cant-s)<<endl;
				ans-=(gauss(cant)-gauss(cant-s));
				cant=0;
			}else{
				cant++;
			}
		}
		ans-=(gauss(cant)-gauss(cant-s));
		cout<<ans<<"\n";
	}
	
	
	return 0;
}




