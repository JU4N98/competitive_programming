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
typedef pair<ll,ll> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,k;
	cin>>n>>k;
	vector<string> arr;
	cin.ignore();
	forn(i,3*n){
		string in;
		getline(cin,in);
		arr.pb(in);
	}
	reverse(arr.begin(),arr.end());
	map<string,ll> m1;
	map<ll,string> m2;
	map<string,ll> cant;
	forn(i,sz(arr)) {
		if(m1.find(arr[i])==m1.end()){
			m1[arr[i]]=i; m2[i]=arr[i];
		}
		cant[arr[i]]++;
	}
	set<pair<ll,ll>> s;
	forn(i,sz(arr)) s.insert({-cant[arr[i]],m1[arr[i]]});
	ll ite=0;
	forall(it,s){
		if(ite>=k) break;
		cout<<m2[it->snd]<<"\n";
		ite++;
	}
	
	
	return 0;
}




