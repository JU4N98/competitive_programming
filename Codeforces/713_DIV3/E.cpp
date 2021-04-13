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
		ll n,l,r,s;
		cin>>n>>l>>r>>s;
		ll minsum=0,maxsum=0;
		vector<bool> arr(n+1,false);
		forr(i,1,r-l+2) minsum+=i;
		forn(i,r-l+1) maxsum+=n-i;

		if(s<minsum || s>maxsum) cout<<"-1\n";
		else{
			ll act=0;
			forr(i,1,r-l+2){
				arr[i]=true;
				act+=i;
			}
			forr(ult,r-l+1,n){
				if(act==s) break;
				forn(i,r-l+1){
					arr[ult-i]=false;
					arr[ult+1-i]=true;
					act++;
					if(act==s) break;
				}
			}
			deque<ll> ans;
			forn(i,n+1) if(arr[i]) ans.pb(i);
			ll cant=1;
			forr(i,1,n+1){
				if(cant<l && !arr[i]){
					ans.push_front(i); 
					cant++;
				}
			}
			cant=0;
			dforn(i,n+1) if(cant<n-r && !arr[i]){
				 ans.pb(i);
				 cant++;
			}
			forn(i,ans.size()) cout<<ans[i]<<" ";
			cout<<"\n"; 
		}
			
		
	}
	
	
	return 0;
}




