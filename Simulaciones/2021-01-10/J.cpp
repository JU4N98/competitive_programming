#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
#define ANARAP
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
	 
	 ll n;
	 cin>>n;
	 vector<ll> arr(n),dp(n+1,0);
	 vector<pair<ll,ll>> trailer(n+1);
	 forn(i,n) cin>>arr[i];
	 bool imp=false;
	 forn(i,n-3) if(arr[i+1]-arr[i]<=1000 && arr[i+2]-arr[i+1]<=1000 && arr[i+3]-arr[i+2]<=1000) imp=true;
	 if(imp || n==1){
		cout<<"Impossible\n";
		return 0; 
	 }
	 dp[0]=1;
	 forn(i,n-1){
		 if(dp[i]==0) continue;
		 ll dif1=arr[i+1]-arr[i], dif2=10000;
		 if(i<n-2) dif2=arr[i+2]-arr[i+1];
		 //cout<<"POSICION "<<i<<endl;
		 //cout<<dif1<<" "<<dif2<<endl;
		 if(dif1<=1000 && dif2<=1000){
			//cout<<i+3<<endl;
			if(trailer[i+3].fst==0 && trailer[i+3].snd==0){
				trailer[i+3].fst=trailer[i].fst;
				trailer[i+3].snd=trailer[i].snd+1;
				dp[i+3]=dp[i];
			}else{
				if(trailer[i+3].fst!=trailer[i].fst || trailer[i+3].snd!=trailer[i].snd+1) dp[i+3]+=dp[i];
			}
		 }else if(dif1<2000 ){
			 //cout<<i+2<<endl;
			 if(trailer[i+2].fst==0 && trailer[i+2].snd==0){
				trailer[i+2].fst=trailer[i].fst+1;
				trailer[i+2].snd=trailer[i].snd;
				dp[i+2]=dp[i];
			}else{
				if(trailer[i+2].fst!=trailer[i].fst+1 || trailer[i+2].snd!=trailer[i].snd) dp[i+2]+=dp[i];
			}
			 if(dif2<2000){
				 //cout<<i+3<<endl;
				 if(trailer[i+3].fst==0 && trailer[i+3].snd==0){
					 trailer[i+3].fst=trailer[i].fst;
					 trailer[i+3].snd=trailer[i].snd+1;
					 dp[i+3]=dp[i];
				 }else{
					 if(trailer[i+3].fst!=trailer[i].fst || trailer[i+3].snd!=trailer[i].snd+1) dp[i+3]+=dp[i];
				 }
			 }
		 }
		 //forn(i,n+1)cout<<dp[i]<<" ";
		 //cout<<endl;
	 }
	 
	 //cout<<dp[n]<<" "<<endl;
	 if(dp[n]==0){
		 cout<<"Impossible\n"; 
	 }else if(dp[n]==1){
		 cout<<"Cars without trailers: "<<trailer[n].fst<<"\n";
		 cout<<"Cars with trailers: "<<trailer[n].snd<<"\n";
	 }else{
		cout<<"Ambiguous\n"; 
	 }
	 
	 
	 return 0;
}


