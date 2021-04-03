#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b; a<c; a++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define ll long long
//#define ANARAP
vector<bool> ctr;
ll arr [9] = {1,2,3,4,5,6,7,8,9};

ll bt(ll n, ll count){
	if(n==0){
		return true;
	}else if(count==9 && n!=0){
		return false;
	}else {
		for(int i=8;i>-1;i--){
			if(!ctr[i]){
				ctr[i]=true;
				if(bt(n-arr[i],count+1)) return true;
				ctr[i]=false;
			}
		}
	}
	return false;
}

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		cin>>n;
		ctr.resize(9,false);
		if(!bt(n,0)){
			cout<<"-1\n";
		}else{
			forn(j,9){
				if(ctr[j]){
					cout<<arr[j];
				}
			}
			cout<<"\n";
		}
		ctr.clear();
	}
	
	return 0;
}
