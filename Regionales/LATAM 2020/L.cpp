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
typedef pair<ll,ll> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,x;
	cin>>n>>x;
	vector<ii> arr(n);
	forn(i,n){
		cin>>arr[i].fst>>arr[i].snd;
		arr[i].snd+=arr[i].fst;
	}
	sort(arr.begin(),arr.end());
	ll overlaps=LLONG_MAX,idx=-1;
	forn(i,481){
		ll sum=0;
		forn(j,n){
			if(arr[j].snd<i) continue;
			if(arr[j].fst<i) arr[j].fst=i;
			ll ini = ((arr[j].fst-i)+x-1)/x;
			ll fin = ((arr[j].snd-i)/x);
			sum+=fin-ini+1;
		}
		if(sum<overlaps){
			overlaps=sum;idx=i;
		}
	}
	cout<<idx<<" "<<overlaps<<endl;
	return 0;
}




