#include <bits/stdc++.h>
#define forr(i,a,b) for(ll i =(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i = n-1; i>=0; i--)
#define forall(it, v) for(auto it=v.begin(); it!=v.end(); it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP
#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, mat[10][10];
	forn(i,10) forn(j,10) mat[i][j]=0;
	cin>>n;
	bool ok=true;
	forn(i,n){
		ll d,l,r,c;
		cin>>d>>l>>r>>c;
		r--;
		c--;
		if(d==0){
			if(c+l-1>=10) ok=false;
			forr(j,c,c+l) mat[r][j]++; 
		}else{
			if(r+l-1>=10) ok=false;
			forr(j,r,r+l) mat[j][c]++;
		}
	}
	
	forn(i,10) forn(j,10) if(mat[i][j]>1) ok=false;
	if(ok) cout<<"Y\n"; else cout<<"N\n";

	return 0;
}
 

