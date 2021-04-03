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
	
	string s;
	cin>>s;
	ll n=s.size();
	cout<<3<<"\n";
	cout<<"L 2\n";
	n++;
	cout<<"R 2\n";
	n+=n-2;
	cout<<"R "<<n-1<<"\n";
	
	return 0;
}
