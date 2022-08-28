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
	
	string sday; cin >> sday;
	ll day = 0;
	if(sday == "Mon") day = 0;
	else if(sday == "Tue") day = 1;
	else if(sday == "Wed") day = 2;
	else if(sday == "Thu") day = 3;
	else if(sday == "Fri") day = 4;
	else if(sday == "Sat") day = 5;
	else day = 6;
	
	ll n; cin >> n;
	ll ans = 32LL;
	
	vector<ll> date(n); 
	forn(i,n) cin >> date[i];
	forn(i,n){
		if(date[i] == 0){
			ll add = 30 ;
			if((day+add)%7 == 5) add += 2;
			if((day+add)%7 == 6) add += 1;
			ans = min(ans,add);
			continue;
		}
		
		ll cur = (day-date[i]) % 7;
		
		while(date[i]>0 && cur != 0){
			cur = (cur+30)%7;
			date[i] -= 30;
			if(cur == 5){ cur = 0; date[i] -= 2; }
			if(cur == 6){ cur = 0; date[i] -= 1; }
		}
		
		if(date[i] > 0) date[i] %= 91;
		
		while(date[i]>0){
			cur = (cur+30)%7;
			date[i] -= 30;
			if(cur == 5){ cur = 0; date[i] -= 2; }
			if(cur == 6){ cur = 0; date[i] -= 1; }
		}
		
		ans = min(abs(date[i]),ans);
	}
	cout << ans << "\n";
	
	
	return 0;
}




