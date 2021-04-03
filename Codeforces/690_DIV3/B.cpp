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



int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		string s;
		cin>>n>>s;
		if(s[0]=='2'){
			if(s[1]=='0'){
				if(s[2]=='2'){
					if(s[3]=='0'){
						cout<<"YES\n";
					}else{
						if(s[n-1]=='0'){
							cout<<"YES\n";
						}else{
							cout<<"NO\n";
						}
					}
				}else{
					string aux;
					aux+=s[n-2];
					aux+=s[n-1];
					if(aux=="20"){
						cout<<"YES\n";
					}else{
						cout<<"NO\n";
					}
				}
			}else{
				string aux;
				aux+=s[n-3];
				aux+=s[n-2];
				aux+=s[n-1];
				if(aux=="020"){
					cout<<"YES\n";
				}else{
					cout<<"NO\n";
				}
			}
		}else{
			string aux;
			aux+=s[n-4];
			aux+=s[n-3];
			aux+=s[n-2];
			aux+=s[n-1];
			if(aux=="2020"){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
	}
	
	return 0;
}
