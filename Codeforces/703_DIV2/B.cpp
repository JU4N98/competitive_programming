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
#define ANARAP

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
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		vector<ii> arr(n);
		vector<ll> arrx(n),arry(n),prefix(n+1),sufix(n+1);
		forn(i,n){
			ll x,y;
			cin>>x>>y;
			arr[i]={x,y};
			arrx[i]=x;
			arry[i]=y;
		}
		
		sort(arrx.begin(),arrx.end());
		sort(arry.begin(),arry.end());
		ll medianx = LLONG_MAX, mediany = LLONG_MAX;
		if(n%2==0){
			ll aux=0;
			forn(i,n) aux += abs(arrx[i]-arrx[n/2]); 
			medianx = min(medianx,aux);
			aux=0;
			forn(i,n) aux += abs(arrx[i]-arrx[n/2-1]); 
			medianx = min(medianx,aux);
			aux=0;
			forn(i,n) aux += abs(arry[i]-arry[n/2]); 
			mediany = min(mediany,aux);
			aux=0;
			forn(i,n) aux += abs(arry[i]-arry[n/2-1]); 
			mediany = min(mediany,aux);
		}else{
			medianx=0;
			mediany=0;
			forn(i,n) medianx += abs(arrx[i]-arrx[n/2]); 
			forn(i,n) mediany += abs(arrx[i]-arry[n/2]); 
		}
		set<ll> s;
		forr(i,1,n+1) prefix[i]=arrx[i-1]+prefix[i-1];
		for(int i =n-1;i>-1;i--) sufix[i]=arrx[i]+sufix[i+1];
		forn(i,n){
			cout<<arrx[i]<<" "<<arrx[i]*(i)-prefix[i] + sufix[i]-arrx[i]*(n-i)<<endl;
			if(arrx[i]*(i)-prefix[i] + sufix[i]-arrx[i]*(n-i) == medianx) s.insert(arrx[i]);
		}
		ll ans = s.size();
		
		
		s.clear();
		forr(i,1,n+1) prefix[i]=arry[i-1]+prefix[i-1];
		for(int i =n-1;i>-1;i--) sufix[i]=arry[i]+sufix[i+1];
		forn(i,n) if(arry[i]*(i)-prefix[i] + sufix[i]-arry[i]*(n-i) == mediany) s.insert(arry[i]);
		ans*=s.size();
		cout<<ans<<"\n";
	}
	
	return 0;
}




