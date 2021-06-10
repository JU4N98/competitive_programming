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
typedef pair<ll,ll> ii;
ll n,m;

void func(vector<ii> &l, vector<ii> &r, vector<ll> &ans){
		set<ii> sl;
		forn(i,sz(l)){
			sl.insert({l[i].fst,i});
		}
		//~ forall(it,sl){
			//~ cout<<it->fst<<" "<<it->snd<<" | ";
		//~ }
		//~ cout<<endl;
		//~ forn(i,sz(r)) cout<<r[i].fst<<" "<<r[i].snd<<" | ";
		//~ cout<<endl;
		//~ forn(i,sz(l)) cout<<l[i].fst<<" "<<l[i].snd<<" | ";
		//~ cout<<endl;
		dforn(i,sz(r)){
			if(!sl.empty() && sl.lower_bound(r[i])!=sl.end()){
				ii li = *(sl.lower_bound(r[i]));
				ans[r[i].snd]=(li.fst-r[i].fst)/2;
				ans[l[li.snd].snd]=(li.fst-r[i].fst)/2;
				r[i]={-1LL,-1LL};
				l[li.snd]={-1LL,-1LL};
				sl.erase(li);
			}
		}
		//~ forn(i,sz(r)) cout<<r[i].fst<<" "<<r[i].snd<<" | ";
		//~ cout<<endl;
		//~ forn(i,sz(l)) cout<<l[i].fst<<" "<<l[i].snd<<" | ";
		//~ cout<<endl;
		//~ forn(i,n) cout<<ans[i]<<" ";
		//~ cout<<"\n";
		forn(i,sz(l)){
			ll posp,poss;
			ii pri = {-1LL,-1LL};
			while(i<sz(l) && l[i]==pri) i++;
			if(i<sz(l)){posp=i;pri=l[i];}
			ii seg = {-1LL,-1LL};
			i++;
			while(i<sz(l) && l[i]==seg) i++;
			if(i<sz(l)){poss=i;seg=l[i];}
			
			if(seg.fst!=-1LL){
				ll col = pri.fst + (seg.fst-pri.fst)/2;
				ans[pri.snd]=col;
				ans[seg.snd]=col;
				l[posp]={-1LL,-1LL};
				l[poss]={-1LL,-1LL};
			}
		}
		//~ forn(i,n) cout<<ans[i]<<" ";
		//~ cout<<"\n";
		dforn(i,sz(r)){
			ll posp,poss;
			ii pri = {-1LL,-1LL};
			while(i>-1 && r[i]==pri) i--;
			if(i>-1){posp=i;pri=r[i];}
			ii seg = {-1LL,-1LL};
			i--;
			while(i>-1 && r[i]==seg) i--;
			if(i>-1){poss=i;seg=r[i];}
			
			if(seg.fst!=-1LL){
				ll col = m-pri.fst + ((m-seg.fst)-(m-pri.fst))/2;
				ans[pri.snd]=col;
				ans[seg.snd]=col;
				r[posp]={-1LL,-1LL};
				r[poss]={-1LL,-1LL};
				
			}
		}
		//~ forn(i,n) cout<<ans[i]<<" ";
		//~ cout<<"\n";
		ii li={-1LL,-1LL},ri={-1LL,-1LL};
		forn(i,sz(l)) if(l[i].fst!=-1LL) li=l[i];
		forn(i,sz(r)) if(r[i].fst!=-1LL) ri=r[i];
		if(li.fst!=-1LL && ri.fst!=-1LL){
			ll col=0;
			//~ cout<<li.fst<<" "<<ri.fst<<endl;
			cout<<"\n";
			if(li.fst<m-ri.fst){
				col+=li.fst;
				ri.fst+=li.fst;
				col+=m-ri.fst;
				li.fst=m-ri.fst;
				col+=(m-li.fst)/2;
			}else{
				col+=m-ri.fst;
				li.fst-=col;
				col+=li.fst;
				ri.fst=m-li.fst;
				col+=(ri.fst)/2;
			}
			ans[li.snd]= col;
			ans[ri.snd]= col;
		}
	
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
		
		cin>>n>>m;
		vector<ii> l,r;
		vector<ll> arr(n),ans(n,-1LL);
		forn(i,n) cin>>arr[i];
		forn(i,n) {
			char dir;
			cin>>dir;
			if(dir=='R') r.pb({arr[i],i});
			else l.pb({arr[i],i}); 
		}
		
		vector<ii> lp,li,rp,ri;
		forn(i,sz(l)){
			if(l[i].fst%2==0) lp.pb(l[i]);
			else li.pb(l[i]);
		}
		forn(i,sz(r)){
			if(r[i].fst%2==0) rp.pb(r[i]);
			else ri.pb(r[i]);
		}
		sort(li.begin(),li.end());
		sort(ri.begin(),ri.end());
		sort(lp.begin(),lp.end());
		sort(rp.begin(),rp.end());
		func(li,ri,ans);
		//~ forn(i,n) cout<<ans[i]<<" ";
		//~ cout<<"\n";
		func(lp,rp,ans);
		forn(i,n) cout<<ans[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}




