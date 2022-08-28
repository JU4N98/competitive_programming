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
typedef pair<ll,ll> ii;

struct obj{
	ll x,y;
	char type;
	
	obj (ll xi, ll yi, char typei){ x=xi, y=yi, type=typei;}
};

void add(map<ll,int> &dp, obj o, ll h){
	ll x1 = (o.x - o.y)%(2*h);
	ll x2 = (o.x + o.y)%(2*h);
	dp[x1]++;
	dp[x2]++;
}

void maxi(map<ll,int> &dp, obj o, ll h){
	ll x1 = (o.x - o.y)%(2*h);
	ll x2 = (o.x + o.y)%(2*h);
	dp[x1] = max(dp[x1],dp[x2]);
	dp[x2] = dp[x1];
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
		// height input
		ll h; cin >> h;
		
		// woods input
		vector<obj> objects;
		int n; cin >> n;
		forn(N,n){
			ll x,y; cin >> x >> y; objects.pb(obj(x,y,'w'));
		} 
		
		// coins input
		int m; cin >> m;
		forn(M,m){
			ll x,y; cin >> x >> y; objects.pb(obj(x,y,'c'));
		}
		
		// sorts the objects by higher x
		sort(objects.begin(),objects.end(),[](obj a, obj b){return a.x > b.x;});
		
		// solve the dp
		map<ll,int> dp;
		forn(i,sz(objects)){
			ll currx = objects[i].x;
			while(i<sz(objects) && objects[i].x == currx){
				// if it is a coin then add 1 to the trajectories
				if(objects[i].type == 'c'){
					add(dp,objects[i],h);
				// if it is a table then update trajectories with the maximum value
				}else{
					maxi(dp,objects[i],h);
				}
				i++;
			}
			i--;
		}
		
		cout << dp[0] << "\n";
	}
	
	return 0;
}




