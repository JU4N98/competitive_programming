#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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
		ll n;
		string s;
		vector<bool> aux;
		cin>>n;
		aux.resize(n,false);
		cin>>s;
		ll izq=0, der=0, amb=0, ans=0;
		forn(j,n){
			switch(s[j]){
				case '-':
					amb++;
				break;
				case '<':
					izq++;
				break;
				case '>':
					der++;
				break;
			}
		}
		if(izq==0 || der==0){
			cout<<n<<"\n";
		}else{
			forn(j,n){
				if(s[j]=='-'){
					if(!aux[j]){
						ans++;
						aux[j]=true;
					}
					if(!aux[(j+1)%n]){
						ans++;
						aux[(j+1)%n]=true;
					}
				}
			}
			cout<<ans<<"\n";
		}
		
	}
	
	return 0;
} 
