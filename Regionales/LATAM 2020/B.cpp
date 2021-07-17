#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
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
vector<ll> arr;

bool getv(ll i){
	return ((arr[i+1]==-1 || arr[i+1]>=arr[i]) && (arr[i-1]==-1 || arr[i-1]>=arr[i])) || arr[i]==-1;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin>>n;
	arr.resize(n);
	forn(i,n) cin>>arr[i];
	
	ll cantv=0;
	vector<bool> valle(n,false);
	forr(i,1,n-1){
		ll l=i-1,r=i+1;
		while(arr[r]==arr[i]) r++;
		
		if(arr[i]!=-1 && arr[l]>arr[i] && arr[i]<arr[r]){
			forr(j,l+1,r) valle[j]=true;
			cantv++;
		}
		i=r-1;
	}
	
	bool ans=false;
	forr(i,3,n+1){
		ll sum=0;
		if(n%i<3 && n%i!=0) continue;
		bool ok=true;
		
		for(ll j=i-1;j<n-1;j+=i){
			if(!(valle[j] || valle[j+1] || getv(j) || getv(j+1))){
				ok=false;
			}else{
				if(valle[j] || valle[j+1]) sum++;
			}
		}
		if(sum>=cantv && ok ){
			ans=true;	
		}
		if(!(arr[n-2]>=arr[n-1] || arr[n-1]==-1 || arr[n-2]==-1)) ans=false;
		if(!(arr[1]>=arr[0] || arr[0]==-1 || arr[1]==-1)) ans=false;
	}
	
	if(ans) cout<<"Y\n";
	else cout<<"N\n";
	
	
	return 0;
}




