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
	
	ifstream f; 
	f.open("encrypted.pdf",ios::binary);
	char bytes[7724];
	f.read(bytes,7724);
	f.close();
    string ans="";
	
	char bytes2[7724];
    forn(x,256){
		ofstream o;
		o.open(to_string(x)+".pdf");
		forn(j,7724){
			bytes2[j] = ((bytes[j]-(x+j))%256+256)%256;
		}
		o.write(bytes2,7724);
		o.close();
		ans="";
	}
    
    
	
	return 0;
}




