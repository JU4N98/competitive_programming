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
	
	ll n;
	cin>>n;
	ll l=1, r=n, med, sec=-1,sec2, ans;
	while(r-l>2){
		cout<<"? "<<l<<" "<<r<<endl;
		cin>>sec;
		med=(l+r)/2;
		if(sec<=med){
			cout<<"? "<<l<<" "<<med<<endl;
			cin>>sec2;
			if(sec2==sec){
				r=med;
			}else{
				l=med+1;
			}
		}else{
			cout<<"? "<<med+1<<" "<<r<<endl;
			cin>>sec2;
			if(sec2==sec){
				l=med+1;
			}else{
				r=med;
			}
		}
	}
	if(r-l==2){
		cout<<"? "<<l<<" "<<r<<endl;
		cin>>sec;
		med=(l+r)/2;
		if(sec<=med){
			cout<<"? "<<l<<" "<<med<<endl;
			cin>>sec2;
			if(sec2==sec){ if(sec==l) ans=med; else ans=l; }else ans=r;
		}else{
			cout<<"? "<<l<<" "<<med<<endl;
			cin>>sec2;
			if(sec2==med) ans=l; else ans=med;
		}
	}else if(r-l==1){
		cout<<"? "<<l<<" "<<r<<endl;
		cin>>sec2;
		if(sec2==l) ans=r; else ans=l;
	}else if(r==l){
		ans=r;
	}
	cout<<"! "<<ans<<endl;
	
	
	return 0;
}




