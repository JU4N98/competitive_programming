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
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		vector<vector<char>> mat(n);
		vector<ii> ptos; 
		forn(i,n){
			mat[i].resize(n);
			string s;
			cin>>s;
			forn(j,n){
				mat[i][j]=s[j];
				if(s[j]=='*'){
					ptos.pb({i,j});
				}
			}
		}
		if(ptos[0].fst==ptos[1].fst){
			if(ptos[0].fst>0){
				mat[ptos[0].fst-1][ptos[0].snd]='*';
				mat[ptos[1].fst-1][ptos[1].snd]='*';
			}else{
				mat[ptos[0].fst+1][ptos[0].snd]='*';
				mat[ptos[1].fst+1][ptos[1].snd]='*';
			}
		}else if(ptos[0].snd==ptos[1].snd){
			if(ptos[0].snd>0){
				mat[ptos[0].fst][ptos[0].snd-1]='*';
				mat[ptos[1].fst][ptos[1].snd-1]='*';
			}else{
				mat[ptos[0].fst][ptos[0].snd+1]='*';
				mat[ptos[1].fst][ptos[1].snd+1]='*';
			}
		}else{
			mat[ptos[0].fst][ptos[1].snd]='*';
			mat[ptos[1].fst][ptos[0].snd]='*';
		}
		forn(i,n){
			forn(j,n){
				cout<<mat[i][j];
			}
			cout<<"\n";
		}
	}
	
	
	return 0;
}




