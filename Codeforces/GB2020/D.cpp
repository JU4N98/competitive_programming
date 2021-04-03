#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b; a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define snd second
#define fst first
#define pb push_back
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		vector<ll> w(n),degree(n),ans;
		ll ansa = 0;
		forn(i,n){
			cin>>w[i];
			ansa+=w[i];
		}
		
		forn(i,n-1){
			ll a,b;
			cin>>a>>b;
			degree[a-1]++; degree[b-1]++;
		}
		
		forn(i,n){
			while(degree[i]>1){
				ans.pb(w[i]);
				degree[i]--;
			}
		}
		
		sort(ans.begin(),ans.end(),greater<ll>());
		
		cout<<ansa<<" ";
		forn(i,n-2){
			ansa+=ans[i];
			cout<<ansa<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}

