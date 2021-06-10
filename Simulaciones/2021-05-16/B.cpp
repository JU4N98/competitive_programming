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
const ll mod = 104206969LL;
int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int mes[12]={1,2,3,4,5,6,7,8,9,10,11,12}, dias[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	ll anio=0;
	forn(i,12){
		forr(j,1,dias[i]+1){
			ll aux=j,act=mes[i];
			while(aux>0){
				act*=10;
				aux/=10;
			}
			act+=j;
			anio+=act;
		}
	}
	
	ll a,b;
	cin>>a>>b;
	a--;
	//cout<<anio*5<<endl;
	ll ansa = a%mod*anio%mod + ((a/4)-(a/100)+(a/400))%mod* 229 + anio + 229;
	if(a==-1) ansa=0LL;
	ll ansb = b%mod*anio%mod + ((b/4)-(b/100)+(b/400))%mod* 229 + anio + 229;
	cout<<((ansb-ansa)%mod+mod)%mod<<"\n";
	
	return 0;
}




