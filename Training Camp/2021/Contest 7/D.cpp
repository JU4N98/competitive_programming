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
	
	ll n,sum=0; cin>>n;
	set<ii> s1,s2;
	forn(i,n){
		ll in; cin>>in;
		sum+=in;
		s1.insert({in,i});
		s2.insert({i,in});
	}
	ll ans=0,curr=0;
	while(!s1.empty()){
		bool brk=false;
		while(!brk){
			ii act = *(s1.rbegin());
			ii act2 = {act.snd,act.fst};
			s1.erase(act);
			if(act2 == *(s2.begin()) || act2== *(s2.rbegin())){
				if(curr%2==0) ans+=act.fst; else ans-=act.fst;
				s2.erase(act2);
				brk=true;
			}else{
				auto ite = s2.find(act2);
				ii m = *ite, a=*(prev(ite)), b =*(next(ite));
				s2.erase(m); s2.erase(a); s2.erase(b);
				s1.erase({a.snd,a.fst}); s1.erase({b.snd,b.fst});
				ii sig = {m.fst,-m.snd+a.snd+b.snd};
				s2.insert(sig); 
				s1.insert({sig.snd,sig.fst});
			}
		}
		curr++;
	}
	
	ans = (ans+sum)/2;
	cout<<ans<<"\n";
	
	return 0;
}




