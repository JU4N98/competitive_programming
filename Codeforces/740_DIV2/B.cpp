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

void prep(vector<int> &arr, int a, int b){
	forn(i,sz(arr)){
		if(i%2==0 && a>0){
			arr[i]=1;
			a--;
		}
	}
	forn(i,sz(arr)){
		if(i%2==1 && a>0){
			arr[i]=1;
			a--;
		}
	}
	forn(i,sz(arr)){
		if(i%2==1 && b>0 && arr[i]!=1){
			arr[i]=2;
			b--;
		}
	}
	forn(i,sz(arr)){
		if(i%2==0 && b>0 && arr[i]!=1){
			arr[i]=2;
			b--;
		}
	}
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
		int a,b; cin>>a>>b;
		vector<int> arr1(a+b), arr2(a+b);
		prep(arr1,a,b);
		prep(arr2,b,a);
		set<int> ans;
		int a1=0,a2=0;
		forn(i,sz(arr1)){
			if(i%2==0){
				if(arr1[i]!=1) a1++;
				if(arr2[i]!=1) a2++;
			}else{
				if(arr1[i]!=2) a1++;
				if(arr2[i]!=2) a2++;
			}
		}
		ans.insert(a1); ans.insert(a2);
		forn(i,sz(arr1)-1){
			if(i%2==0){
				if(arr1[i]==1 && arr1[i+1]==2){
					arr1[i]=2; arr1[i+1]=1; a1+=2;
				}
				if(arr2[i]==1 && arr2[i+1]==2){
					arr2[i]=2; arr2[i+1]=1; a2+=2;
				}
			}else{
				if(arr1[i]==2 && arr1[i+1]==1){
					arr1[i]=1; arr1[i+1]=2; a1+=2;
				}
				if(arr2[i]==2 && arr2[i+1]==1){
					arr2[i]=1; arr2[i+1]=2; a2+=2;
				}
			}
			ans.insert(a1); ans.insert(a2);
		}
		cout<<sz(ans)<<"\n";
		forall(it,ans) cout<<*it<<" ";
		cout<<"\n";
	}
	
	return 0;
}




