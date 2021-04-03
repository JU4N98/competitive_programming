#include <bits/stdc++.h>
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
		//freopen("output","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n;
		cin>>n;
		set<pair<ll,ll>,greater<pair<ll,ll>>> bh;
		vector<ll> htw(n);
		vector<vector<ll>> datos(n), solve(n);
		forn(i,n){
			ll h,w;
			cin>>h>>w;
			bh.insert({min(h,w),i});
			vector<ll> datosaux(3);
			datosaux[0]=max(w,h);
			datosaux[1]=i;
			datosaux[2]=-1;
			datos[i]=datosaux;
		}
		ll idx=0;
		forall(it,bh){
			pair<ll,ll> p = *it;
			solve[idx] = datos[p.snd];
			htw[p.snd] = idx;
			idx++;
		}
		
		ll mini=-1;
		dforn(i,solve.size()){
			if(mini==-1){
				solve[i][2]=i;
				mini=i;
			}else{
				if(solve[i][0]<solve[mini][0]){
					solve[i][2]=i;
					mini=i;
				}else{
					solve[i][2]=mini;
				}
			}
		}
		
		set<pair<ll,ll>> ans;
		forall(it,bh){
			pair<ll,ll> p = *it;
			auto it2 = (bh.upper_bound({p.fst,-1}));
			if(it2==bh.end()){
				ans.insert({p.snd,-1});
			}else{
				ll idxa = htw[(*it2).snd], idxb = htw[p.snd];
				//cout<<solve[idxa][2]<<" "<<idxb<<endl;
				//cout<<solve[solve[idxa][2]][0]<<" "<<solve[idxb][0]<<endl;
				if(solve[solve[idxa][2]][0]<solve[idxb][0]){
					ans.insert({p.snd,solve[solve[idxa][2]][1]+1});
				}else{
					ans.insert({p.snd,-1});
				}
			}
		}
		forall(it,ans){
			cout<<(*it).snd<<" ";
		}
		cout<<"\n";
		
	}
	
	return 0;
}
