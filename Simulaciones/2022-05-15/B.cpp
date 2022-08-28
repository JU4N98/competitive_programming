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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

ll eulerPhi2(ll n) // O (sqrt n)
{ 
	ll r = n;
	forr(i,2,n+1)
	{
		if((ll)i*i>n) break;
		if(n%i==0)
		{
			while(n%i==0) n/=i;
			r -= r/i;
		}
	}
	if (n != 1) r-= r/n;
	return r;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; 
	while(cin>>n){
		cout << eulerPhi2(n)/2 << "\n";
	}
	
		
	return 0;
}




