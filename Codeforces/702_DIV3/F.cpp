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
		map<ll,ll> m,cant;
		forn(i,n){
			ll aux;
			cin>>aux;
			if(m.find(aux)==m.end()) m[aux]=1;
			else m[aux]++;
		}
		forall(i,m){
			ll aux = i->snd;
			if(cant.find(aux)==cant.end()) cant[aux]=1;
			else cant[aux]++;
		}
		vector<ll> prefix(cant.size()+1),sufix(cant.size()+1);
		ll pos = 1;
		forall(i,cant){
			prefix[pos]+=(i->snd)*(i->fst) + prefix[pos-1];
			pos++;
		}
		pos=cant.size()-1;
		for(auto ite = cant.rbegin(); ite!=cant.rend(); ite++){
			sufix[pos]+=(ite->snd)*(ite->fst) + sufix[pos+1];
			pos--;
		}
		ll ans = LLONG_MAX, acum=0, tot=m.size();
		pos=0;
		//forall(i,cant){
		//	cout<<i->fst<<" "<<i->snd<<endl;
		//}
		//forn(i,cant.size()+1) cout<<prefix[i]<<" ";
		//cout<<endl;
		//forn(i,cant.size()+1) cout<<sufix[i]<<" ";
		//cout<<endl;
		forall(i,cant){
			acum+=i->snd;
			ans=min(ans,prefix[pos]+sufix[pos+1]-(tot-acum)*(i->fst));
			pos++;
		}
		cout<<ans<<"\n";
		//cout<<endl;
	}
	
	
	return 0;
}




