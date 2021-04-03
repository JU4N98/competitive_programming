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
		//cout<<endl;
		ll n;
		cin>>n;
		vector<ll> in(n);
		forn(i,n) cin>>in[i];
		bool sol = true;
		ll c=in[1]-in[0],m=-1,maxi=LLONG_MIN;
		forn(i,n) maxi = max(maxi,in[i]);
		if(c==0){
			forn(i,n-1) if(in[i]!=in[i+1]) sol=false;
			if(sol) cout<<"0\n"; else cout<<"-1\n";
		}else if(c>0){
			forn(i,n-1){
				if(in[i+1]<in[i]){
					if(m==-1) m = in[i]+c-in[i+1];
					else if(m!=in[i]+c-in[i+1]){
						sol=false;
					}
					if(in[i+1]+m-in[i]!=c) sol=false;
					//cout<<in[i+1]+m-in[i]<<" ";
				}else{
					if(in[i+1]-in[i]!=c) sol=false;
					//cout<<in[i+1]-in[i]<<" ";
				}
			}
			//cout<<"\n";
			if(sol && (m==-1 || m>maxi)){
				if(m!=-1) cout<<m<<" "<<c<<"\n"; else cout<<"0\n";
			}else{
				cout<<"-1\n";
			}
		}else if(c<0){
			forn(i,n-1){
				if(in[i+1]>in[i]){
					if(m==-1) m = abs(in[i]+c)+in[i+1];
					else if(m!=abs(in[i]+c)+in[i+1]){
						sol=false;
					}
					if(in[i+1]-m-in[i]!=c) sol=false;
					//cout<<in[i+1]-m-in[i]<<" ";
				}else{
					if(in[i+1]-in[i]!=c) sol=false;
					//cout<<in[i+1]-in[i]<<" ";
				}
			}
			//cout<<"\n";
			if(sol && (m==-1 || m>maxi)){
				if(m!=-1) cout<<m<<" "<<m+c<<"\n"; else cout<<"0\n";
			}else{
				cout<<"-1\n";
			}
		}
		
	}
	
	return 0;
}




