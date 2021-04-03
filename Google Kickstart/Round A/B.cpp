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
ll calc(ll base, ll largo){
	return max(min(base,largo/2)-1,0LL)+ max(min(largo,base/2)-1,0LL);
}
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
		vector<vector<vector<ll>>> mat;
		ll ans=0,r,c;
		cin>>r>>c;
		mat.resize(r);
		ans=0;
		forn(i,r){
			mat[i].resize(c);
			forn(j,c){
				mat[i][j].resize(5);
				cin>>mat[i][j][0];
			}
		}
		
		forn(i,r){
			ll acum=0;
			forn(j,c){
				if(mat[i][j][0]==0) acum=0; else acum++;
				mat[i][j][2] = acum;
			}
			acum=0;
			dforn(j,c){
				if(mat[i][j][0]==0) acum=0; else acum++;
				mat[i][j][1] = acum;
			}
		}
		forn(j,c){
			int acum=0;
			forn(i,r){
				if(mat[i][j][0]==0) acum=0; else acum++;
				mat[i][j][3] = acum;
			}
			acum=0;
			dforn(i,r){
				if(mat[i][j][0]==0) acum=0; else acum++;
				mat[i][j][4] = acum;
			}
		}
		/*
		forn(i,5){
			forn(j,r){
				forn(k,c){
					cout<<mat[j][k][i]<<" ";
				}
				cout<<"\n";
			}
			cout<<"\n";
		}
		* */
		// 3 arriba 4 abajo 1 derecha 2 izquierda
		forn(i,r){
			forn(j,c){
				int largo, base;
				// arriba derecha
				largo=mat[i][j][3];
				base=mat[i][j][1];
				ans+=calc(base,largo);
				//cout<<i<<" "<<j<<" "<<ans<<endl;
				//arriba izquierda
				base=mat[i][j][2];
				ans+=calc(base,largo);
				//cout<<i<<" "<<j<<" "<<ans<<endl;
				//abajo izquierda
				largo=mat[i][j][4];
				ans+=calc(base,largo);
				//cout<<i<<" "<<j<<" "<<ans<<endl;
				base=mat[i][j][1];
				ans+=calc(base,largo);
				//cout<<i<<" "<<j<<" "<<ans<<endl;
			}
		}
		cout<<"Case #"<<T+1<<": "<<ans<<"\n";
		mat.clear();
	}
	
	return 0;
}




