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
#define ANARAP

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
		n++;
		cout<<"N "<<n<<endl;
		vector<ll> digits;
		ll aux=n;
		while(aux!=0LL){
			digits.pb(aux%10LL);
			aux/=10;
		}
		reverse(digits.begin(),digits.end());
		vector<vector<ll>> tams(sz(digits)+1);
		forr(i,1,sz(digits)){
			if(sz(digits)%i==0){
				for(int j=0;j<sz(digits);j+=i){
					ll auxi=0LL;
					forn(k,i) auxi+=digits[j+k]*pow(10,i-k-1);
					tams[i].pb(auxi);
				}
			}
		}
		forn(i,sz(tams)){
			forn(j,sz(tams[i])) cout<<tams[i][j]<<" ";
			if(sz(tams[i])>0)cout<<"\n";
		}
		//cout<<"\n";
		
		ll ans=0;
		for(int k=sz(digits)+1;ans==0;k++){
			for(int i=1;i<k;i++){
				if(k%i==0 && pow(10,i)-pow(10,i-1)>=k/i){
					ll pri=pow(10,i-1);
					ans=pri;
					for(int j=i;j<k;j+=i) ans*=pow(10,i), ans+=pri+(j/i);
				}
			}
			
		}
		
		cout<<ans<<endl;
		forr(i,1,sz(tams)){
			if(sz(tams[i])==0) continue;
			ll lim=0;
			forn(j,sz(tams)) lim*=10,lim+=9;
			bool sol=true;
			forn(j,sz(tams[i])-1){
				if(tams[i][j]<tams[i][j+1] && tams[i][j]+1!=tams[i][j+1]) sol=false;
			}
			if(sol){
				cout<<"I "<<i<<endl;
				ll pri=tams[i][0],ans1=0;
				ans1=pri;
				for(int j=i;j<sz(digits);j+=i) ans1*=pow(10,i), ans1+=pri+(j/i);
				ans=min(ans,ans1);
			}else{
				forn()
			}
		}
		cout<<"ANS "<<ans<<endl;
	}
	
	
	return 0;
}




