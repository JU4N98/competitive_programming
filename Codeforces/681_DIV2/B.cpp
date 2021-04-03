#include<bits/stdc++.h>
using namespace std;


#define dbg(x) cerr<<#x<<"="<<x<<endl;
#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define pb(i) push_back(i)
#define fst first
#define snd second
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	ll t;
	cin>>t;
	forn(i,t){
		ll a,b;
		string s;
		cin>>a>>b;
		cin>>s;
		
		ll sum=0;
		ll ult=-1;
		
		forn(j,s.size()){
			if(s[j]=='1'){
				if(ult==-1 || (j-ult-1)*b>a){
					sum+=a;
				}else{
					sum+=(j-ult-1)*b;
				}
				while(s[j]=='1') j++;
				ult=j-1;
			}
		}
		cout<<sum<<"\n";
	}
	
	
} 
