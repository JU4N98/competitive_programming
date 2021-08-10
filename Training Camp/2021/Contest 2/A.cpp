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
const ll inf = 1000000010;
ll n,m,v,k,d,shoots,tact;
multiset<pair<ii,ll>> zombies;
vector<ii> spikes;
vector<ll> prefix,ans;

ll spikedmg(ii zombie, ll ti){
	ll distance = (ti - zombie.fst +1)*v;
	if(distance<=0) return 0;
	ii spk =  {distance,LLONG_MAX};
	auto it = upper_bound(spikes.begin(),spikes.end(),spk);
	ll idx = 0;
	if(it==spikes.end()){
		if(spikes[m-1].fst<=distance) idx=m;
	}else{
		idx = it-spikes.begin();
	}
	return prefix[idx];
}

void solve(ii zombie, ll pos){
	ll dmg = spikedmg(zombie,tact-1);
	if(zombie.fst>tact-1) shoots=0;
	
	if(dmg>=zombie.snd){
		ll idx;
		if(upper_bound(prefix.begin(),prefix.end(),zombie.snd)==prefix.end()) idx = m-1;
		else idx = upper_bound(prefix.begin(),prefix.end(),zombie.snd) - prefix.begin()-1;
		ans[pos] = (spikes[idx].fst+v-1)/v + zombie.fst -1;
	} else if(dmg+shoots*d>=zombie.snd){
		ans[pos] = tact-1;
		ll consumo = (zombie.snd-dmg+d-1)/d;
		shoots -= consumo;
	} else{
		zombie.snd -= shoots*d;
		tact = max(tact,zombie.fst);
		ll l=tact,r=1000000000000000;
		while(l<r){
			ll med = (l+r)/2;
			ll dmg2 = spikedmg(zombie,med);
			dmg2 = min(dmg2 + min(min(min((med - tact + 1),inf)*k,inf)*d,inf),inf);
			if(dmg2>=zombie.snd){
				r = med;
			}else{
				l = med+1;
			}
		}
		ans[pos]=l;
		if(zombie.snd>=spikedmg(zombie,l)){
			shoots = (l-tact+1)*k - ((zombie.snd-spikedmg(zombie,l)+d-1)/d);
		}else{
			shoots = k;
		}
		tact = l + 1;
	}
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m>>v>>k>>d;
	forn(i,n){
		pair<ii,ll> zombie;
		cin>>zombie.fst.fst;
		zombie.fst.snd=i;
		cin>>zombie.snd;
		zombies.insert(zombie);
	}
	ans.resize(n);
	spikes.resize(m);
	prefix.resize(m+1,0);
	forn(i,m){
		cin>>spikes[i].fst>>spikes[i].snd;
	}
	sort(spikes.begin(),spikes.end());
	forn(i,m) prefix[i+1]=prefix[i]+spikes[i].snd;
	
	tact=1; shoots=0;
	while(!zombies.empty()){
		pair<ii,ll> zombiea = *(zombies.begin()); zombies.erase(zombies.begin());
		ii zombie = {zombiea.fst.fst,zombiea.snd};
		ll idx = zombiea.fst.snd;
		solve(zombie,idx);
	}
	
	forn(i,n) cout<<ans[i]<<" ";
	cout<<"\n";
	
	return 0;
}




