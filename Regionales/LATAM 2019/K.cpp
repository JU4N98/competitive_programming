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

ll exp(ll a,ll b){
	ll x=1, y=a;
	while(b>0)
	{
		if(b%2==1) x=(x*y);
		y*=y;
		b/=2;
	}
	return x;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string ah; cin>>ah;
	vector<ll> poly(1); poly[0]=1;
	forn(i,sz(ah)-1){
		if(ah[i]!=ah[i+1]){
			ll pos = (i+1)*2+1;
			poly.pb(0);
			for(int j=sz(poly)-1;j>0;j--){
				poly[j]+=poly[j-1]*(-pos);
			}
		}
	}
	
	ll ansi=0;
	forn(j,sz(poly)){
		ansi+=poly[j]*exp(2,sz(poly)-1-j);
	}
	
	cout<<sz(poly)-1<<"\n";
	if((ah[0]=='H' && ansi>0) || (ah[0]=='A' && ansi<0)){
		forn(i,sz(poly)) cout<<poly[i]<<" ";
	}else{
		forn(i,sz(poly)) cout<<-poly[i]<<" ";
	}
	cout<<"\n";
	
	
	return 0;
}




