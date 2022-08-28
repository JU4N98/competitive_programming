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
vector<int> aux(20);

bool isValidRow(int mask, vector<int> & mat){
	int pos = 0, crece = 0;
	forn(i,20) if(mask&(1<<i)) aux[pos++]=mat[i];
	forr(i,1,pos){
		if(crece == 0) crece = aux[i]-aux[i-1]<0? -1 : 1;
		else if((crece==-1 && aux[i]-aux[i-1]>0) 
		|| (crece==-1 && aux[i]-aux[i-1]>0)) return false;
	}
	return true;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int r,c; cin >> r >> c;
	vector<vector<int>> mat(r,vector<int>(c));
	forn(i,r) forn(j,c) cin >> mat[i][j];
	
	vector<vector<int>> maskc(c,vector<int>(c));
	
	forn(i,c){
		forr(j,i+1,c){
			forn(k,r){
				maskc[i][j] |= ((1<<k)&(mat[k][j]-mat[k][i] > 0));
			}
		}
	}
	
	ll ans = 0;
	forr(i,1,pow(2,c)){
		vector<ll> dp(r,1);
		forn(j,r){
			dp[j] = isValidRow(i, mat[j]);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}




