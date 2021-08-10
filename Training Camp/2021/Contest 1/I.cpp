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

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m;
	cin>>n>>m;
	vector<vector<char>> mat(n);
	
	ii s,t;
	forn(i,n){
		mat[i].resize(m);
		forn(j,m){
			cin>>mat[i][j];
			if(mat[i][j]=='S') s.fst=i,s.snd=j;
			if(mat[i][j]=='T') t.fst=i,t.snd=j;
		}
	}
	
	vector<ll> col,fil;
	forn(j,m){
		bool ok=true;
		forr(i,min(s.fst,t.fst),max(s.fst,t.fst)+1){
			if(mat[i][j]=='*') ok=false;
		}
		if(ok) col.pb(j);
	}
	
	forn(i,n){
		bool ok=true;
		forr(j,min(s.snd,t.snd),max(s.snd,t.snd)+1){
			if(mat[i][j]=='*') ok=false;
		}
		if(ok) fil.pb(i);
	}
	
	bool ans=false;
	forn(i,sz(col)){
		bool ok=true;
		forr(j,min(s.snd,col[i]),max(s.snd,col[i])+1LL) if(mat[s.fst][j]=='*') ok=false;
		forr(j,min(t.snd,col[i]),max(t.snd,col[i])+1LL) if(mat[t.fst][j]=='*') ok=false;
		if(ok)ans=true;
	}
	
	forn(i,sz(fil)){
		bool ok=true;
		forr(j,min(s.fst,fil[i]),max(s.fst,fil[i])+1LL) if(mat[j][s.snd]=='*') ok=false;
		forr(j,min(t.fst,fil[i]),max(t.fst,fil[i])+1LL) if(mat[j][t.snd]=='*') ok=false;
		if(ok) ans=true;
	}
	
	if(ans) cout<<"YES\n";
	else cout<<"NO\n";
	
	
	return 0;
}




