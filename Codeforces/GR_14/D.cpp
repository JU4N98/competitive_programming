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
	
	ll t;
	cin>>t;
	forn(T,t){
		ll n,il,ir;
		cin>>n>>il>>ir;
		map<ll,ll> l,r;
		forn(i,n){
			ll col;
			cin>>col;
			if(i<il){ 
				if(l.find(col)!=l.end()) l[col]++; else l[col]=1;
				if(r.find(col)==r.end()) r[col]=0;
			}else{
				if(r.find(col)!=r.end()) r[col]++; else r[col]=1;
				if(l.find(col)==l.end()) l[col]=0;
			}
		}
		
		//~ forall(it,l) cout<<it->fst<<" ";
		//~ cout<<"\n";
		//~ forall(it,l) cout<<it->snd<<" ";
		//~ cout<<"\n";
		//~ forall(it,r) cout<<it->snd<<" ";
		//~ cout<<"\n";
		//~ cout<<"\n";
		
		ll ans=0,taml=il,tamr=ir;
		forall(it,l){
			ll col = it->fst,cl=it->snd,cr=r[col];
			while(taml>tamr && cl-cr>1){
					cl--,cr++;
					taml--;
					tamr++;
					ans++;
			}
			while(taml<tamr && cr-cl>1){
					cl++,cr--;
					taml++;
					tamr--;
					ans++;
			}
			l[col]=cl;
			r[col]=cr;
		}
		
		//~ forall(it,l) cout<<it->fst<<" ";
		//~ cout<<"\n";
		//~ forall(it,l) cout<<it->snd<<" ";
		//~ cout<<"\n";
		//~ forall(it,r) cout<<it->snd<<" ";
		//~ cout<<"\n";
		//~ cout<<"ANS "<<ans<<"\n";
		//~ cout<<"\n";
		
		forall(it,l){
			ll col = it->fst,cl=it->snd,cr=r[col];
			if(taml>tamr && cl-cr==1){
					cl--,cr++;
					taml--;
					tamr++;
					ans++;
			}
			while(taml<tamr && cr-cl==1){
					cl++,cr--;
					taml++;
					tamr--;
					ans++;
			}
			l[col]=cl;
			r[col]=cr;
		}
		
		//~ forall(it,l) cout<<it->fst<<" ";
		//~ cout<<"\n";
		//~ forall(it,l) cout<<it->snd<<" ";
		//~ cout<<"\n";
		//~ forall(it,r) cout<<it->snd<<" ";
		//~ cout<<"\n";
		//~ cout<<"ANS "<<ans<<"\n";
		//~ cout<<"\n";
		
		ll sum=0;
		forall(it,l){
			ll col = it->fst,cl=it->snd,cr=r[col];
			sum+=abs(cl-cr);
		}
		cout<<ans+sum/2<<"\n";
		
	}
	
	
	return 0;
}




