#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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

struct node{
	int v[4];
};

map<ll, int> dist;
ll getHash(node x){
	ll ret = 0;
	ll pot = 21;
	forn(i,4){
		ret += pot*(10+x.v[i]);
		pot *= 21;
	}
	return ret;
}

int calc(int a, int b, bool subo){
	if(subo){
		if(a <= b)return b-a;
		else return 10-a+b;
	}
	else{
		if(a>=b) return a-b;
		else return 10-b+a;
	}
}

void bfs(){
	queue<node> q;
	node st;
	st.v[0] = 0, st.v[1]=0, st.v[2]=0, st.v[3]=0;
	ll oc = getHash(st);
	//~ cout << "OK " << oc << endl;
	dist[oc]=0;
	
	q.push(st);
	int cnt = 0;
	while(!q.empty()){
		cnt++;
		node aux = q.front();
		q.pop();
		ll haux = getHash(aux);
		bool ok = 0;
		if(ok) continue;
		forn(i,4){
			forr(j,i,4){
				node nxt = aux;
				node nxt2 = aux;
				forr(k,i,j+1){
					nxt.v[k]++;
					nxt2.v[k]--;
					nxt.v[k] = (((nxt.v[k]%10)+10)%10);
					nxt2.v[k] = (((nxt2.v[k])%10)+10)%10;
				}
				ll hnxt = getHash(nxt), hnxt2 = getHash(nxt2);
				//~ cout << hnxt << " " << hnxt2 << endl;
				if(!dist.count(hnxt)){
					dist[hnxt]=dist[haux]+1;
					q.push(nxt);
				};
				if(!dist.count(hnxt2)){
					dist[hnxt2]=dist[haux]+1;
					q.push(nxt2);
				};
			}
		}
	}
	return;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	bfs();
	int t; cin >> t;
	forn(T,t){
		string a, b; cin >> a >> b;
		int ans = 100;
		node noba;
		forn(i,4) noba.v[i] = ((((a[i]-b[i])%10)+10)%10);
		ans = min(ans, dist[getHash(noba)]);
		cout << ans << '\n';
	}
	
	return 0;
}






