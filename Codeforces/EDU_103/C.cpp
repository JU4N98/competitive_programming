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
		vector<ll> c(n),a(n),b(n);
		forn(i,n) cin>>c[i];
		forn(i,n) cin>>a[i];
		forn(i,n) cin>>b[i];
		ll cur=0,ans=0;
		bool nuevo=true;
		for(int i=n-1;i>-1;i--){
			//cout<<"cur "<<cur<<" ans "<<ans<<endl;
			if(nuevo){
				if(a[i]!=-1 && a[i]==b[i]){
					//cout<<"a"<<endl;
					ans=max(ans,c[i]+1);
					cur=0;
				}else if(b[i]==-1 || a[i]==-1){
					//cout<<"b"<<endl;
					cur=0;
				}else{
					//cout<<"c"<<endl;
					cur=c[i]+1;
					nuevo=false;
				}
			}else{
				ans=max(ans,cur+abs(b[i+1]-a[i+1]));
				//cout<<"cur "<<cur<<" abs "<<abs(b[i+1]-a[i+1])<<endl;
				if(a[i]!=-1 && a[i]==b[i]){
					//cout<<"d"<<endl;
					cur=max(cur+c[i]-max(a[i+1],b[i+1])+min(a[i+1],b[i+1])-1,c[i]-1);
					ans=max(ans,cur+2);
					cur=0;
					nuevo=true;
				}else if(b[i]==-1 || a[i]==-1){
					//cout<<"e"<<endl;
					cur=0;
					nuevo=true;
				}else{
					//cout<<"f"<<endl;
					cur=max(cur+c[i]-max(a[i+1],b[i+1])+min(a[i+1],b[i+1])-1,c[i]-1);
					cur+=2;
				}
				
			}
		}
		//cout<<"cur "<<cur<<" ans "<<ans<<endl;
		cout<<ans<<"\n";
	}
	
	
	return 0;
}



