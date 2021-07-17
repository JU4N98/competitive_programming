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
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		multiset<ll,greater<ll>> pq1,pq2;
		multiset<ll> s1,s2;
		ll sum1=0,sum2=0;
		forn(i,n){
			ll in;
			cin>>in;
			sum1+=in;
			s1.insert(in);
		}
		forn(i,n){
			ll in;
			cin>>in;
			sum2+=in;
			s2.insert(in);
		}
		
		while(sz(s1)>n-(n/4)){ pq1.insert(*(s1.begin())); sum1-=*(s1.begin()); s1.erase(s1.begin());}
		while(sz(s2)>n-(n/4)){ pq2.insert(*(s2.begin())); sum2-=*(s2.begin()); s2.erase(s2.begin());}
		
		ll ans=0;
		while(sum1<sum2){
			n++;
			ans++;
			pq1.insert(100);
			pq2.insert(0);
			while(*(s1.begin())<*(pq1.begin())){
				ll aux=*(s1.begin());
				sum1-=aux;
				sum1+=*(pq1.begin());
				s1.erase(s1.begin());
				s1.insert(*(pq1.begin()));
				pq1.erase(pq1.begin());
				pq1.insert(aux);
			}
			while(sz(s1)<n-(n/4)){ s1.insert(*(pq1.begin())); sum1+=*(pq1.begin()); pq1.erase(pq1.begin());}
			while(sz(s2)<n-(n/4)){ s2.insert(*(pq2.begin())); sum2+=*(pq2.begin()); pq2.erase(pq2.begin());}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}




