#include <bits/stdc++.h>
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
#define MAXN 1000
#else
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

#define MAXZOOM 35

vector<ii> g[MAXN][MAXZOOM];
ll dist[MAXN][MAXZOOM], n;
vector<ii> v;

void bfs()
{
	ll node = -1;
	forn(i,n) if(v[i].fst == 0) node = i;
	assert(node != -1);
	queue<ii> q;
	q.push(mp(node, 1));
	memset(dist, -1, sizeof(dist));
	dist[node][1] = 0;
	while(!q.empty())
	{
		ii cur = q.front();
		//cout << "cur " << cur.fst << ' ' << cur.snd << ' ' << dist[cur.fst][cur.snd] << '\n';
		q.pop();
		forall(it, g[cur.fst][cur.snd]) if(dist[it->fst][it->snd] == -1)
		{
			dist[it->fst][it->snd] = dist[cur.fst][cur.snd] + 1;
			//cout << "go to " << it->fst << ' ' << it->snd << ' ' << dist[it->fst][it->snd] << '\n';
			q.push(*it);
		}
	}
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll k;
	cin >> n >> k;
	v = vector<ii>(n+1);
	forn(i,n)
	{
		cin >> v[i].fst;
		v[i].snd = i;
	}
	v[n++] = mp(0, -1);
	sort(v.begin(), v.end());
	//cout << "nodes: ";
	//forn(i,n) cout << v[i].fst << ' ' << v[i].snd << '\n';
	vector<ll> maxGoodZoom(n,0);
	forn(i,n)
	{
		forn(j,MAXZOOM-1) g[i][j].pb(mp(i,j+1));
		forr(j,1,MAXZOOM) g[i][j].pb(mp(i,j-1));
		ll l,r, width = 1, lpos = i, rpos = i;
		set<ii> s;
		s.insert(mp(v[i].snd, i));
		forr(j,1,MAXZOOM)
		{
			l = v[i].fst - width;
			r = v[i].fst + width;
			width *= 2;
			while(lpos-1 >= 0 && v[lpos-1].fst >= l)
			{
				lpos--;
				s.insert(mp(v[lpos].snd, lpos));
				if(sz(s) > k) s.erase(s.begin());
			}
			while(rpos+1 < n && v[rpos+1].fst <= r)
			{
				rpos++;
				s.insert(mp(v[rpos].snd, rpos));
				if(sz(s) > k) s.erase(s.begin());
			}
			if(s.count(mp(v[i].snd, i))) maxGoodZoom[i] = j;
			forall(it, s)
			{
				//cout << "from " << i << ' ' << j << " to " << it->snd << ' ' << j  << '\n';
				g[i][j].pb(mp(it->snd, j));
			}
		}
	}
	bfs();
	vector<ll> ans(n-1);
	forn(i,n) if(v[i].fst != 0)
	{
		ll aux = -1;
		forn(j,maxGoodZoom[i]) if(aux == -1 || (dist[i][j] != -1 && dist[i][j] < aux)) aux = dist[i][j];
		ans[v[i].snd] = aux;
	}
	forn(i,n-1) cout << ans[i] << '\n';
	return 0;
}
