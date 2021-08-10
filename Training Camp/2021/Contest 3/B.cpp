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
#define fst firstF
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
	
	ll n,k;
	cin>>n>>k;
	vector<ll> arr(n); forn(i,n) cin>>arr[i];
	set<ii> s;
	map<ll,ii> m;
	forn(i,k){
		if(m.find(arr[i])==m.end() || (*(m.find(arr[i]))).fst==0){
			s.insert({-1,arr[i]});
			m[arr[i]] = {-1,arr[i]};
		}else{
			ii p = m[arr[i]];
			s.erase(p);
			p.fst--;
			s.insert(p);
			m[arr[i]]=p;
		}
	}
	ii p = *(s.rbegin());
	if(p.fst<-1) cout<<"Nothing\n";
	else cout<<p.snd<<"\n";
	ll l = 0;
	
	//~ forall(it,s) cout<<"("<<it->fst<<","<<it->snd<<") ";
	//~ cout<<endl;
	
	forr(i,k,n){
		ii p1 = m[arr[l]];
		s.erase(p1);
		p1.fst++;
		if(p1.fst!=0) s.insert(p1);
		m[arr[l]]=p1;
		l++;
		
		if(m.find(arr[i])==m.end() || (*(m.find(arr[i]))).fst==0){
			s.insert({-1,arr[i]});
			m[arr[i]] = {-1,arr[i]};
		}else{
			ii p2 = m[arr[i]];
			s.erase(p2);
			p2.fst--;
			 s.insert(p2);
			m[arr[i]]=p2;
		}
		
		//~ forall(it,s) cout<<"("<<it->fst<<","<<it->snd<<") ";
		//~ cout<<endl;
		ii p3 = *(s.rbegin());
		if(p3.fst<-1) cout<<"Nothing\n";
		else cout<<p3.snd<<"\n";
	}
	
	
	return 0;
}




