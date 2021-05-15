#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
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
		freopen("input.in","r",stdin);
	#endif 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	double m,n,r;
	cin>>m>>n>>r;
	double lx,ly,pi=acos(-1.0),ax,bx,ay,by,ans;
	cin>>ax>>ay>>bx>>by;
	assert(m!=-1 && n!=-1 && r!=1);
	if(n==0){
		cout<<fixed<<setprecision(7)<<0.0<<"\n";
	}else if(m==0){
		cout<<fixed<<setprecision(7)<<(r/n)*abs(by-ay);
	}else{
		lx=(r/n);
		ly=(lx*min(by,ay)*pi)/m;
		ans=lx*abs(by-ay)+ly*abs(bx-ax);
		ans=min(ans,(by+ay)*lx);
		cout<<fixed<<setprecision(7)<<ans<<"\n";
	}
	return 0;
}
