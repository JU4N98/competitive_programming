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
	
	ll n;
	cin>>n;
	string s;
	cin>>s;
	vector<ll> letras(26),fact(21);
	fact[0]=1;
	forr(i,1,21) fact[i]=fact[i-1]*i;
	forn(i,n) letras[s[i]-'a']++;
	ll ans=1;
	bool secure=false;
	forn(i,26){
		if(letras[i]>0){
			ans*=(fact[n]/fact[n-letras[i]]);
			ans/=fact[letras[i]];
		}
		if(ans>=365*24*60*60 || ans<0) secure=true;
		n-=letras[i];
	}
	
	if(secure) cout<<"Secure\n";
	else cout<<floor(ans)<<"\n";
	
	
	return 0;
}




