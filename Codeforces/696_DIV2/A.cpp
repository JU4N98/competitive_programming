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
		string a="",b;
		cin>>n>>b;
		a+="1";
		forn(i,n-1){
			int sum =0;
			sum+=b[i]-'0';
			sum+=a[i]-'0';
			if(sum==2){
				if(b[i+1]-'0'==1){
					a+="0";
				}else if(b[i+1]-'0'==0){
					a+="1";
				}
			}else if(sum==1){
				if(b[i+1]-'0'==1){
					a+="1";
				}else if(b[i+1]-'0'==0){
					a+="0";
				}
			}else if(sum==0){
				if(b[i+1]-'0'==1){
					a+="1";
				}else if(b[i+1]-'0'==0){
					a+="1";
				}
			}
		}
		cout<<a<<"\n";
	}
	
	
	
	return 0;
}
