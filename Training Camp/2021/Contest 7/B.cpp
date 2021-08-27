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
	
	ll n,w; cin>>n>>w;
	vector<int> a(n);
	vector<ii> b(n);
	forn(i,n){
		cin>>a[i]>>b[i].fst;
		b[i].snd=i;
	}
	sort(b.begin(),b.end());
	
	
	
	ll ini=-1;
	forn(i,-1,n){
		if((i+1)*2+(n-i)>=w){
			ini=i;
			break;
		}
	}
	vector<int> ans(n);
	multiset<ii> sel,pq;
	ll sum = 0, cant=0;
	forr(i,ini+1){
		sel.insert({a[b[i].snd],b[i].snd});
		pq.insert({b[i].fst-a[b[i].snd],b[i].snd});
		ans[b[i].snd]=1;
		sum+=a[b[i].snd];
		cant++;
	}
	forr(i,ini+1,n){
		pq.insert({a[b[i].snd],b[i].snd});
	}
	while(cant<k){
		ii act = *(pq.begin());
		sel.insert(act);
		pq.erase(pq.begin());
		ans[act.snd]++;
		cant++;
		sum += act.fst;
	}
	forr(i,ini+1,n){
		if(ans[i]==0){
			sel.insert({b[i].fst-a[b[i].snd],b[i].snd});
			pq.erase({b[i].fst-a[b[i].snd],b[i].snd});
			cant++;
		}
		while((*(sel.rbegin())).fst>(*(pq.begin())).fst){
			ii ult = *(sel.rbegin()); sel.erase(ult);
			if(ult)
			ii pri = *(pq.begin()); pq.erase(pri);
		}
		while(cant>k){
			
		}
	}
	
	
	return 0;
}




