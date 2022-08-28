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
#define ALL(v) v.begin(),v.end()

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef long long td;
typedef vector<int> vi;
typedef vector<td> vd;

const td INF = 0;
bool zero(td x){ return x==0; }

struct Hungarian{
	int n; vector<vd> cs; vi L,R;
	
	Hungarian(int N, int M): n(max(N,M)), cs(n,vd(n)), L(n), R(n){
		forr(x,0,N) forr(y,0,M) cs[x][y] = INF;
	}
	
	void set(int x, int y, td c){ cs[x][y] = c; }
	
	td assign(){
		int mat = 0; vd ds(n), u(n), v(n); vi dad(n), sn(n);
		
		forr(i,0,n) u[i] = *min_element(ALL(cs[i]));
		forr(j,0,n){ 
			v[j] = cs[0][j] - u[0]; 
			forr(i,1,n) v[j] = min(v[j],cs[i][j]-u[i]);
		}
		L=R=vi(n,-1);
		
		forr(i,0,n)	forr(j,0,n)
			if(R[j]==-1 && zero(cs[i][j]-u[i]-v[j])){L[i]=j;R[j]=i;mat++;break;}
		
		for(;mat<n;mat++){
			int s = 0, j = 0, i;
			while(L[s] != -1) s++;
			fill(ALL(dad),-1); fill(ALL(sn),0);
			forr(k,0,n) ds[k] = cs[s][k]-u[s]-v[k];
			for(;;){
				j = -1;
				forr(k,0,n) if(!sn[k] && (j==-1||ds[k]<ds[j])) j = k;
				sn[j] = 1; i = R[j];
				if(i == -1) break;
				forr(k,0,n) if(!sn[k]){
					auto new_ds = ds[j] + cs[i][k]-u[i]-v[k];
					if(ds[k] > new_ds){ ds[k] = new_ds; dad[k] = j;}
				}
			}
			forr(k,0,n) if(k != j && sn[k]){ 
				auto w = ds[k]-ds[j]; v[k]+=w, u[R[k]] -= w;
			}
			u[s] += ds[j];
			while(dad[j] >= 0 ){ int d = dad[j]; R[j]=R[d]; L[R[j]]=j;j=d;}
			R[j] = s; L[s] = j;
		}
		td value = 0; forr(i,0,n) value += cs[i][L[i]];
		return value;
	}
};


int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<ii> amy(n);
	vector<ll> b(n),c(n);;
	
	forn(i,n) cin >> amy[i].fst;
	forn(i,n) cin >> amy[i].snd;
	forn(i,n) cin >> b[i];
	forn(i,n) cin >> c[i];
	
	sort(ALL(amy));
	vector<ll> power(n), point(n+1);
	forn(i,n) power[i] = amy[i].fst;
	forn(i,n) point[i+1] = amy[i].snd + point[i];
	
	Hungarian H = Hungarian(n,n);
	
	forn(i,n){
		forn(j,n){
			ll idx = lower_bound(ALL(power),b[i]+c[j])-power.begin();
			H.set(i,j,-point[idx]);
		}
	}
	
	cout << -H.assign() << "\n";
	
	return 0;
}




