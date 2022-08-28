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
		ll n, d; cin >> n >> d;
		vector<ll> exams(n+1); forn(i,n) cin >> exams[i+1];
		multiset<ll> dif;
		forr(i,1,n+1){
			//~ cout << exams[i]-exams[i-1]-1 << " ";
			dif.insert(exams[i]-exams[i-1]-1);
		}
		//~ cout << "\n";
		ll ans = *(dif.begin());
		
		forr(i,1,n+1){
			ll act = exams[i]-exams[i-1]-1;
			dif.erase(dif.find(act));
			if(i != n){
				dif.erase(dif.find(exams[i+1]-exams[i]-1));
				dif.insert(exams[i+1]-exams[i-1]-1);
			}
			
			ll ne = (*(dif.rbegin())-1)/2;
			dif.insert(ne);
			ans = max(ans,*(dif.begin()));
			dif.erase(dif.find(ne));
			
			if(i!=n){
				dif.insert(d-exams[n]-1);
				ans = max(ans,*dif.begin());
				dif.erase(dif.find(d-exams[n]-1));
			}else{
				dif.insert(d-exams[n-1]-1);
				ans = max(ans,*dif.begin());
				dif.erase(dif.find(d-exams[n-1]-1));
			}
			
			dif.insert(act);
			if(i!=n){
				dif.insert(exams[i+1]-exams[i]-1);
				dif.erase(dif.find(exams[i+1]-exams[i-1]-1));
			}
			
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




