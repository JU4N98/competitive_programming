#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b;a<c:a++)
#define forn(i,n) forr(i,0,n)
#define dbg(x) cerr<<#x<<"="x<<endl;
#define pb push_back
#define fst first
#define snd second
#define ll long long
#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	ll l,k;
	while(cin>>l){
		cin>>k;
		ll ans = (l-k)*2-1+(l-k+1)*2+1;
		cout<<ans<<endl; 
	}
}
