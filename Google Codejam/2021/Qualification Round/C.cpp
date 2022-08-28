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

vector<ll> recur(ll c, ll n,ll num){
	if(n==1){
		vector<ll> ans;
		ans.pb(num);
		return ans;
	}else{
		ll pos = min(n,c-(n-2));
		vector<ll> aux = recur(c-pos,n-1,num+1);
		//cout<<"aux: ";
		//forn(i,aux.size()) cout<<aux[i]<<" ";
		//cout<<endl;
		vector<ll> ans(n);
		forr(i,pos,n){
			ans[i]=aux[i-1];
		}
		forn(i,pos-1){
			ans[pos-i-2]=aux[i];
		}
		ans[pos-1]=num;
		return ans;
	}
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,c;
		cin>>n>>c;
		cout<<"Case #"<<T+1<<": ";
		if((n*(n+1))/2<c+1 || c<n-1){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		vector<ll> ans;
		ans = recur(c,n,1);
		forn(i,ans.size()) cout<<ans[i]<<" ";
		cout<<endl;
	}
	
	return 0;
}




