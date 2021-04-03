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
#define ANARAP

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
	
	
		ll n;
		cin>>n;
		vector<ll> perm(n),largos;
		forn(i,n) cin>>perm[i];
		ll ope, largo=2,maxlargo=2;
		if(perm[0]<perm[1]) ope=0;
		else ope=1;
		forr(i,2,n){
			if(ope==0){
				if(perm[i-1]<perm[i]) largo++;
				else{
					if(largo>maxlargo){
						maxlargo=largo;
						largos.clear();
						largos.pb(i-1);
					}else if(largo==maxlargo){
						largos.pb(i-1);
					}
					largos.pb(i-1);
					largo=2;
					ope=1;
				}
			}else{
				if(perm[i-1]>perm[i]) largo++;
				else{
					if(largo>maxlargo){
						maxlargo=largo;
						if(largos.size()>0){  
							ll aux = largos[largos.size()-1];
							largos.clear();
							largos.pb(aux);
						}
					}else if(largo<maxlargo){
						largos[largos.size()-1]=-1;
					}
					largo=2;
					ope=0;
				}
			}
		}
		if(ope==0){
			if(largo>maxlargo){
				maxlargo=largo;
				largos.clear();
				largos.pb(n-1);
			}else if(largo==maxlargo){
				largos.pb(n-1);
			}
		}else{
			if(largo>maxlargo){
				maxlargo=largo;
				ll aux = largos[largos.size()-1];
				largos.clear();
				largos.pb(aux);
			}else if(largo<maxlargo){
				largos[largos.size()-1]=-1;
			}
		}
		forn(i,largos[i]) cout<<largos[i]<<" ";
		cout<<endl;
		set<ll> s;
		forn(i,largos.size()) if(largos[i]!=-1) s.insert(largos[i]);
		if(s.size()==1 && maxlargo%2==1) cout<<"1\n"; else cout<<"0\n";
	
	return 0;
}




