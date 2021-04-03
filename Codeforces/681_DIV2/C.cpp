#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define pb(i) push_back(i)
#define fst first
#define snd second
#define ll long long
//#define ANARAP


int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		cin>>n;
		vector<ll> a(n),b(n);
		forn(j,n) cin>>a[j];
		forn(j,n) cin>>b[j];
		vector<pair<ll,ll>> pares;
		forn(j,n){
			pair<ll,ll> p ={a[j],b[j]};
			pares.pb(p);
		}
		sort(pares.begin(),pares.end(),greater<pair<ll,ll>>());
		ll sum=0, ans=pares[0].fst;
		forn(j,n){
			if(sum<pares[j].fst){
				ans=pares[j].fst;
			}
			if(sum==pares[j].fst){
				ans=pares[j].fst;
				break;
			}
			if(sum>pares[j].fst){
				break;
			}
			sum+=pares[j].snd;
		}
		cout<<min(ans,sum)<<endl;
		pares.clear();
		a.clear();
		b.clear();
	}
	
} 
