#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b; a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define snd second
#define fst first
#define pb push_back
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(T,t){
		string s;
		cin>>s;
		vector<bool> usado(s.size(),false);
		
		ll ans=0;
		forn(i,s.size()){
			if(i>0 && !usado[i-1] && s[i]==s[i-1]){
				usado[i]=1;
				ans++;
			} else if(i>1 && !usado[i-2] && s[i]==s[i-2]){
				usado[i]=1;
				ans++;
			}
		}
		
		cout<<ans<<"\n";

	}
	
	return 0;
}

