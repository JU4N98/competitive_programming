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
	forn(i,t){
		vector<ll> v(3);
		cin>>v[0]>>v[1]>>v[2];
		sort(v.begin(),v.end());
		ll sum = v[0]+v[1]+v[2];
		if(sum%9==0 && sum/9<=v[0]){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
		
		v.clear();
	}
	
	return 0;
}
