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
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		string a, b;
		vector<ll> prefix(n+1,0);
		cin>>a>>b;
		forr(i,1,a.size()+1) if(a[i-1]=='1') prefix[i]=prefix[i-1]+1; else prefix[i]=prefix[i-1];
		//forn(i,n+1) cout<<prefix[i]<<" ";
		//cout<<endl;
		bool norm=true;
		bool sol=true;
		//cout<<endl;
		dforn(i,n){
			//cout<<i<<" sol "<<sol<<" norm "<<norm<<" ai "<<a[i]<<" bi "<<b[i]<<" prefix "<<prefix[i+1]<<endl;
			if(a[i]!=b[i] && norm){
				//cout<<" a "<<endl;
				if(prefix[i+1]*2!=i+1){
					//cout<<"a1"<<endl;
					sol=false;
				}else{
					//cout<<"a2"<<endl;
					if(norm) norm=false; else norm=true;
				}
			}else if(a[i]==b[i] && !norm){
				if(prefix[i+1]*2!=i+1){
					//cout<<"b1"<<endl;
					sol=false;
				}else{
					//cout<<"b2"<<endl;
					if(norm) norm=false; else norm=true;
				}
			}else{
				//cout<<endl;
			}
		}
		if(sol) cout<<"YES\n";
		else cout<<"NO\n";
		
	}
	
	return 0;
}




