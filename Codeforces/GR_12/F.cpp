#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it = v.begin(); it!=v.end(); it++)
#define fst first
#define snd second
#define pb push_back
#define ll long long
#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		string s , ans;
		cin>>n;
		cin>>s;
		ll count[6]={0,0,0,0,0,0};
		forn(j,n){
			switch(s[j]){
				case 't':
					count[0]++;
				break;
				case 'r':
					count[1]++;
				break;
				case 'y':
					count[2]++;
				break;
				case 'g':
					count[3]++;
				break;
				case 'u':
					count[4]++;
				break;
				case 'b':
					count[5]++;
				break;
			}
		}
		forn(j,n){
			if(s[j]!='t' && s[j]!='r' && s[j]!='y' && s[j]!='g' && s[j]!='u' && s[j]!='b'){
				ans+=s[j];
			}
		}
		for(int j=5; j>-1;j--){
			char add;
			switch(j){
				case 0:
					add='t';
				break;
				case 1:
					add='r';
				break;
				case 2:
					add='y';
				break;
				case 3:
					add='g';
				break;
				case 4:
					add='u';
				break;
				case 5:
					add='b';
				break;
			}
			forn(k,count[j]){
				ans+=add;
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
