#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		string s;
		vector<ll> st;
		cin>>s;
		forr(j,0,s.size()){
			if(st.empty()){
				st.pb(s[j]);
			}else{
				ll ant = st.back();
				if(ant=='A' && s[j]=='B'){
					st.pop_back();
				}else if(ant=='B' && s[j]=='B'){
					st.pop_back();
				}else{
					st.pb(s[j]);
				}
			}
		}
		cout<<st.size()<<"\n";
	}
	
	return 0;
} 
