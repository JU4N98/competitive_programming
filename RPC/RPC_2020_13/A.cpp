#include <bits/stdc++.h>
#define forr(i, a,b) for(int i=(a); i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP

#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n, t, s2,p2,c2,s1,p1,c1;
	cin>>n>>t>>s2>>p2>>c2;
	vector<bool> criba(n+1);
	forn(i,n+1) criba[i]=true;
	forr(i,2,n+1){
		if(criba[i]){
			ll j=i*2;
			while(j<n+1){
				criba[j]=false;
				j+=i;
			}
		}
	}
	ll numpri=0,numcomp=0;
	forr(i,2,n+1) if(criba[i]) numpri++; else numcomp++;
	
	s1=((s2-(t/n)*n)%n+n)%n;
	p1=((p2-(t/n)*numpri)%n+n)%n;
	c1=(c2+(t/n)*numcomp)%n;
	
	if(s1==0) s1=n;
	forn(i,t%n){
		if(s1==1) s1=n; else s1--;
		if(s1!=1){
			if(criba[s1]) c1++; else p1--;
		}
	}
	p1=((p1%n)+n)%n;
	c1=((c1%n)+n)%n;
	
	if(p1==0) p1=n;
	if(c1==0) c1=n;
	
	cout<<s1<<" "<<p1<<" "<<c1<<"\n";
	
	return 0;
}
