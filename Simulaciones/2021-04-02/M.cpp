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

struct node{
	bool ignore=false;
	ll id;
	map<string,node> child;
	void agregar(queue<string> &q, bool ignorar){
		if(!q.empty()){
			string s = q.front();
			node nuevo;
			if(child.find(s)==child.end()){
				child[s]=nuevo;
			}
			q.pop();
			ignore=ignorar;
			child[s].agregar(q,ignorar);
		}else{
			ignore=ignorar;
		}
	}
	
	ll recorrer(ll level){
		ll tam=0, cuenta=0, ans=0;
		forall(it,child){
			node n = it->snd;
			if(n.ignore) ans++; else ans+=n.recorrer(level+1);
			cuenta+=n.ignore;
			//cout<<aux<<it->fst<<" "<<n.ignore<<" "<<ans<<endl;
			tam++;
		}
		if(child.size()==0){
			if(ignore) return 1LL; else return 0LL;
		}
		if(cuenta==tam && cuenta!=0 && level!=0) return 1LL;
		else return ans;
	}
	
};

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
		ll n,m;
		cin>>n>>m;
		node root;
		root.id=0;
		string s;
		forn(i,n){
			cin>>s;
			string aux="";
			queue<string> q;
			forn(j,s.size()){
				if(s[j]=='/'){
					q.push(aux);
					aux="";
				}else{
					aux+=s[j];
				}
			}
			if(aux!="") q.push(aux);
			root.agregar(q,true);
		}
		forn(i,m){
			cin>>s;
			string aux="";
			queue<string> q;
			forn(j,s.size()){
				if(s[j]=='/'){
					q.push(aux);
					aux="";
				}else{
					aux+=s[j];
				}
			}
			if(aux!="") q.push(aux);
			root.agregar(q,false);
		}
		cout<<root.recorrer(0)<<"\n";
	}
	
	return 0;
}




