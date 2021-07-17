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

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,a,b;
		cin>>n>>a>>b;
		string arr;
		cin>>arr;
		if(b<0){
			//~ cout<<"a"<<endl;
			int cant0=0,cant1=0;
			forn(i,n){
				int idx=i;
				while(idx<n && arr[idx+1]==arr[i]) idx++;
				if(arr[i]=='0') cant0++; else cant1++;
				i=idx;
			}
			cout<<n*a+(min(cant0,cant1)+1)*b<<"\n";
		}else{
			//~ cout<<"b"<<endl;
			cout<<n*(a+b)<<"\n";
		}
	}
	
	return 0;
}




