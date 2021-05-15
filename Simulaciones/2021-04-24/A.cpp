#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0; i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end(); it++)
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

#else

#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,q;
	cin>>n>>q;
	vector<ll> arr(n);
	forn(i,n) cin>>arr[i];
	map<ll,ll>m;
	forn(i,n){
		forr(j,i,n){
			if(i+j+2<=n) continue;
			if(m.find(i+j+2)==m.end()) m[i+j+2]=arr[i]+arr[j];
			else  m[i+j+2]=min(m[i+j+2],arr[i]+arr[j]);
		}
	}
	cout<<m.size()<<endl;
	//forall(it,m) cout<<it->fst<<" "<<it->snd<<endl;
	
		forn(i,q){
			ll k, ans=LLONG_MAX;
			cin>>k;
			if(k<=n){
				cout<<arr[k-1]<<"\n";
				continue;
			}
			forn(j,n){
				ll div=(k-n-1)/(j+1);
				ll aux=div*arr[j]+m[k-div*(j+1)];
				ans=min(ans,aux);
			}
			
			forall(it,m){
				ll idx = it->fst, val=it->snd;
				if(idx>k) break;
				ll div1=(k-n)/idx,div2=k/idx;
				//cout<<idx<<" "<<div1<<" "<<div2<<endl; 
				ans=min(ans,div1*val+m[k-div1*idx]);
				if(k-div2*idx<n) ans=min(ans,div2*val+arr[k-div2*idx]);
				else ans=min(ans,div2*val+m[k-div2*idx]);
			}
			cout<<ans<<"\n";
		}
	
	return 0;
}
 
 
