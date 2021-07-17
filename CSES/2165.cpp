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
//#define ANARAP

#ifdef ANARAP
	#define MAXN 1000
#else
	#define MAXN 43046721
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
bool visi[MAXN];
int dad[MAXN];
int inv[MAXN];
vector<ii> mov(MAXN);
ll n;

void ha (int pos, vector<int> &v){
	if(pos==n){
		ll val=0;
		forn(i,n) val+=v[i]*pow(3,i);
		inv[val]=v;
	}else{
		forn(i,3){
			v[pos]=i;
			ha(pos+1,v);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	forn(i,pow(3,n)) visi[i]=false,dad[i]=-1;
	vector<int> vv(n,0);
	ha(0,vv);
	
	//~ forn(i,sz(inv)){
		//~ forn(j,sz(inv[i])) cout<<inv[i][j]<<" ";
		//~ cout<<"\n";
	//~ }
	
	ll ini=0,fin=0;
	forn(i,n) fin+=2*pow(3,i);
	
	queue<ll> q;
	q.push(ini);
	vector<int> v(n);
	
	bool pres[3];
	visi[ini]=true;
	
	while(!q.empty()){
		
		ll act=q.front();
		
		q.pop();
		v=inv[act];
		forn(i,3) pres[i]=false;
		vector<int> ord;
		forn(i,n) if(!pres[v[i]]){ ord.pb(i);pres[v[i]]=true;}
		sort(ord.begin(),ord.end());
		
		forn(i,sz(ord)){
			forr(j,i+1,sz(ord)){
				ll u = act;
				u-=pow(3,ord[i])*v[ord[i]];
				u+=pow(3,ord[i])*v[ord[j]];
				if(!visi[u]){
					q.push(u);
					visi[u]=true;
					dad[u]=act;
					mov[u]={v[ord[i]],v[ord[j]]};
				}
			}
			forn(j,3){
				if(!pres[j]){
					ll u = act;
					u-=pow(3,ord[i])*v[ord[i]];
					u+=pow(3,ord[i])*j;
					if(!visi[u]){
						q.push(u);
						visi[u]=true;
						dad[u]=act;
						mov[u]={v[ord[i]],j};
					}
				}
			}
		}
		if(dad[fin]!=-1) break;
	}
	
	vector<ii> ans;
	while(dad[fin]!=-1){
		ans.pb(mov[fin]);
		fin=dad[fin];
	}
	
	cout<<sz(ans)<<"\n";
	dforn(i,sz(ans)){
		cout<<ans[i].fst+1<<" "<<ans[i].snd+1<<"\n";
	}
	
	return 0;
}




