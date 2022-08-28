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

void print(stack<ll> s){
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

bool solve(vector<ll> arr, vector<ll> tar, ll m){
	stack<ll> as, ts;
	dforn(i,sz(arr)) as.push(arr[i]);
	dforn(i,sz(tar)) ts.push(tar[i]);
	
	while(!as.empty() && !ts.empty()){
		ll acta = as.top(); 
		ll actt = ts.top();
		while(acta < actt){
			ts.pop();
			if(actt% m == 0){
				forn(i,m) ts.push(actt/m);
			}else{
				return false;
			}
			actt = ts.top(); 
		}
		
		acta = as.top(); 
		actt = ts.top();
		while(acta > actt){
			as.pop();
			if(acta% m == 0){
				forn(i,m) as.push(acta/m);
			}else{
				return false;
			}
			acta = as.top(); 
		}
		
		as.pop(), ts.pop();
	}
	
	if(!as.empty() || !ts.empty()) return false;
	
	return true;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	forn(T,t){
		ll n,m; cin >> n >> m;
		
		vector<ll> arr(n); 
		forn(i,n) cin >> arr[i];
		
		ll k; cin >> k;
		vector<ll> tar(k);
		forn(i,k) cin >> tar[i];
		
		bool ok = solve(arr,tar,m);
		
		reverse(arr.begin(), arr.end());
		reverse(tar.begin(), tar.end());
		ok |= solve(arr,tar,m);
		
		if(ok) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}




