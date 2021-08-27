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

bool ord(vector<int> &arr){
	bool ans=true;
	forn(i,sz(arr)-1) if(arr[i]>arr[i+1]) ans=false;
	return ans;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin>>t;
	forn(T,t){
		int n; cin>>n;
		vector<int> arr(n);
		forn(i,n) cin>>arr[i];
		int ite=0;
		while(!ord(arr)){
			if((ite+1)%2==1){
				for(int i=0;i<n-1;i+=2){
					if(arr[i]>arr[i+1]){
						int aux=arr[i]; arr[i]=arr[i+1]; arr[i+1]=aux;
					}
				}
			}else{
				for(int i=1;i<n-1;i+=2){
					if(arr[i]>arr[i+1]){
						int aux=arr[i]; arr[i]=arr[i+1]; arr[i+1]=aux;
					}
				}
			}
			ite++;
		}
		cout<<ite<<"\n";
	}
	
	return 0;
}




