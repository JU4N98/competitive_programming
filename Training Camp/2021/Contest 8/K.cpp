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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//~ bool criba[1000000];
	//~ forn(i,1000000) criba[i]=true;
	//~ forr(i,2,1000000){
		//~ if(criba[i]){
			//~ for(int j=i+i;j<1000000;j+=i) criba[j]=false;
		//~ }
	//~ }
	//~ ll count=0;
	//~ forr(i,2,1000000){
		//~ if(criba[i] && i>100000){ cout<<i<<endl; count++;}
		//~ if(count==2) break;
	//~ }
	
	ll n,m; cin>>n>>m;
	cout<<"100003 100003\n";
	forn(i,n-2) cout<<i+1<<" "<<i+2<<" 1\n";
	cout<<n-1<<" "<<n<<" "<<100003-(n-2)<<"\n";
	ll count=0;
	bool corte=false;
	forn(i,n){
		forr(j,i+2,n){
			if(count==m-(n-1)){
				corte=true;
				break;
			}
			cout<<i+1<<" "<<j+1<<" 100019\n";
			count++;
		}
		if(corte) break;
	}
	
	return 0;
}




