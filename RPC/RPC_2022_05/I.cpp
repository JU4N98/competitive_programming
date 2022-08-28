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
bitset<81> mat;
bitset<81> cnt;
int n,m; 
int ans = 0;

//~ int dr[5] = {0,0,0,1,-1}, dc[5] = {0,1,-1,0,0};
//~ void update(int &r, int &c){
	//~ forn(i,5){
		//~ int nr = r + dr[i], nc = c + dc[i];
		//~ if(nr>-1 && nr<n && nc>-1 && nc<m){
			//~ cnt.reset()
		//~ } 
	//~ }
//~ }

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
		cin >> n >> m;
		mat.reset();
		cnt.reset();
		ans = 0;
		
		forn(i,n){
			string r; cin >> r;
			forn(j,m) if(r[j]=='#'){ mat.set(i*m+j); cnt.set(i*m+j); }
		}
		
		if( (mat.count() != 0 && (n<3 || m<3)) 
		|| mat.test(0) 
		|| mat.test(m-1) 
		|| mat.test(m*(n-1)) 
		|| mat.test(m*n-1)){ 
			cout << "Image #" << T+1 << ": impossible\n"; continue;
		}
		
		if(mat.count() == 0){ cout << "Image #" << T+1 << ": 0\n"; continue; }
		
		//~ int base = 0;
		//~ forn(i,n){
			//~ if(mat.test(m*(i-1))){ base++; update(i,1)}
			//~ if(mat.test(m*i-1)){ base++; update(i,m-2)}
		//~ }
		
		//~ forn(i,m){
			//~ if(mat.test(i)){ base++; update(1,i); } 
			//~ if(mat.test(m*(n-1)+i)){base++; update(n-2,i);}
		//~ }
		
		
	}
	
	return 0;
}




