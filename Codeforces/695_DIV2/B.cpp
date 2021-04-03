#include <bits/stdc++.h>
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

vector<ll> arr, hv;
ll n;

ll calc(ll i){
	ll ans=0;
	if(i==0){
		if(arr[i]<arr[i+1]){ ans=-1;}
		else if(arr[i]>arr[i+1]) {ans=1;}
	}else if(i==n-1){
		if(arr[i]<arr[i-1]) {ans=-1;}
		else if(arr[i]>arr[i-1]) {ans=1;}
	}else{
		if(arr[i]<arr[i+1] && arr[i]<arr[i-1]){ ans=-1; }
		else if(arr[i]>arr[i+1] && arr[i]>arr[i-1]) {ans=1; }
	}
	return ans;
}

int main()
{
	// agregar g++ -DANARAP en compilacion
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		cin>>n;
		arr.resize(n,0);
		hv.resize(n,0);
		
		forn(i,n) cin>>arr[i];
		
		ll ans=0;
		forn(i,n){
			if(i==0){
				if(arr[i]<arr[i+1]){ hv[i]=-1;}
				else if(arr[i]>arr[i+1]) {hv[i]=1;}
			}else if(i==n-1){
				if(arr[i]<arr[i-1]) {hv[i]=-1;}
				else if(arr[i]>arr[i-1]) {hv[i]=1;}
			}else{
				if(arr[i]<arr[i+1] && arr[i]<arr[i-1]){ hv[i]=-1; ans++;}
				else if(arr[i]>arr[i+1] && arr[i]>arr[i-1]) {hv[i]=1; ans++;}
			}
		}
		ll ajus=0;
		for(int i=1; i<n-1;i++){
			ll cant =0, cant2=0;
			if(i==1 && i==n-2){
				cant += abs(calc(i));
				arr[i]=arr[i+1];
				cant2 += abs(calc(i));
				ajus=max(ajus,cant-cant2);
			}else if(i==1){
				ll aux=arr[i];
				cant+=abs(calc(i));
				cant+=abs(calc(i+1));
				arr[i]=arr[i+1];
				cant2+=abs(calc(i));
				cant2+=abs(calc(i+1));
				ajus=max(ajus,cant-cant2);
				arr[i]=aux;
			}else if(i==n-2){
				ll aux=arr[i];
				cant+=abs(calc(i));
				cant+=abs(calc(i-1));
				arr[i]=arr[i-1];
				cant2+=abs(calc(i));
				cant2+=abs(calc(i-1));
				ajus=max(ajus,cant-cant2);
				arr[i]=aux;
			}else{
				ll aux=arr[i];
				cant+=abs(calc(i));
				cant+=abs(calc(i-1));
				cant+=abs(calc(i+1));
				arr[i]=arr[i-1];
				cant2+=abs(calc(i));
				cant2+=abs(calc(i-1));
				cant2+=abs(calc(i+1));
				ajus=max(ajus,cant-cant2);
				cant2=0;
				arr[i]=arr[i+1];
				cant2+=abs(calc(i));
				cant2+=abs(calc(i-1));
				cant2+=abs(calc(i+1));
				ajus=max(ajus,cant-cant2);
				arr[i]=aux;
			}
		}
		
		cout<<ans-ajus<<"\n";
		arr.clear();
		hv.clear();
	}
	
	return 0;
}

