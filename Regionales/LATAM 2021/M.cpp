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
#define de first.first
#define ti first.second
#define idx second

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<pair<ii,int>> task(n); forn(i,n){ cin >> task[i].fst.snd >> task[i].fst.fst; task[i].snd = i; }
	sort(task.begin(),task.end());
	
	ll acum = 0; bool ans = true;
	forn(i,n){
		acum += task[i].ti;
		if(acum > task[i].de) ans = false;
	}
	
	ll pre = 0;
	forn(i,n){
		ll maxd = LLONG_MAX; acum = pre;
		forr(j,i,n){
			acum += task[j].ti;
			maxd = min(task[j].de-acum,maxd);
		}
		
		int minidx = i; 
		forr(j,i,n){
			if(task[j].ti <= maxd && task[j].idx < task[minidx].idx) minidx = j;
		}
		
		while(minidx!=i){
			swap(task[minidx],task[minidx-1]);
			minidx--;
		}
		
		pre += task[i].ti;
	}
	
	if(!ans) cout << "*\n";
	else{
		cout << task[0].idx + 1;
		forr(i,1,n) cout << " " << task[i].idx + 1;
		cout << "\n";
	}
	
	return 0;
}




