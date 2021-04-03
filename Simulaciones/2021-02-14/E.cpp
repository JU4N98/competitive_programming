#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.bend();it++)
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

#else

#endif

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main(){
	
	#ifdef ANARAP
	freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,m;
		cin>>n>>m;
		vector<ii> rangos;
		vector<bool> usado(n,false);
		forn(i,n){
			ll a,b;
			cin>>a>>b;
			rangos.pb({max(a,b),min(a,b)});
		}
		sort(rangos.begin(),rangos.end());
		vector<ll> c(m);
		forn(i,m){
			cin>>c[i];
		}
		sort(c.begin(),c.end());
		bool ok=true;
		ll pos=0;
		forn(i,m){
			while(pos<n && !(rangos[pos].snd<=c[i] && rangos[pos].fst>=c[i]) ){
				pos++;
			}
			ok = (pos<n && (rangos[pos].snd<=c[i] && rangos[pos].fst>=c[i]));
			if(!ok) break;
			else{
				usado[pos]=true;
				pos++;
			}
		}
		priority_queue<ll> pq;
		ll suma=0,ans=0;
		pos=n-1;
		dforn(i,m){
			while(!pq.empty() && pq.top()>c[i]){
				suma--;
				pq.pop();
			}
			if(pos>-1) cout<<c[i]<<" "<<rangos[pos].snd<<" "<<rangos[pos].fst<<endl;
			while(pos>-1 && rangos[pos].snd<=c[i] && rangos[pos].fst>=c[i]){
				
			}
			while(pos>-1 && rangos[pos].snd<=c[i] && rangos[pos].fst>=c[i]){
				if(!usado[pos]){
					pq.push(rangos[pos].snd);
					suma++;
				}
				pos--;
			}
			ans=max(suma,ans);
		}
		cout<<ans<<endl;
		if(ok) cout<<"Case #"<<T+1<<": "<<n-(ans)<<endl;
		else cout<<"Case #"<<T+1<<": IMPOSSIBLE!\n";
	}
	
	return 0;
}





