 
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP
#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct trie{
	map<char,trie> m;
	char act='0';
	int sz=0;
	int pos=0;
	void add(const string &s, int p, bool dif, int pos2){
		if(p>=s.size()) return;
		if(act=='0'){
			act=s[p];
			sz=s.size();
			if(dif) pos=pos2;
			else pos=p+1;
			//cout<<"act "<<act<<" sz "<<sz<<" pos "<<pos<<endl;
			m[s[p+1]].add(s,p+1,true,pos);
		}else{
			m[s[p+1]].add(s,p+1,dif,pos);
		}
	}
};

int dfs(string &s, trie *ini){
	trie *ant= ini, *sig;
	int ans=0;
	int tam=s.size();
	forr(p,1,s.size()+1){
		//cout<<p<<endl;
		if((*ant).m.find(s[p])==(*ant).m.end()){
			//cout<<"ant act "<<ant.act<<" pos "<<ant.pos<<" sz "<<ant.sz<<endl;
			//cout<<"sig act "<<sig.act<<" pos "<<sig.pos<<" sz "<<sig.sz<<endl;
			ans+=min((tam-p)+((*ant).sz-p)+2,tam-(*ant).pos+1);
			break;
		}else{
			sig= &((*ant).m[s[p]]);
			//cout<<"ant act "<<ant.act<<" pos "<<ant.pos<<" sz "<<ant.sz<<endl;
			//cout<<"sig act "<<sig.act<<" pos "<<sig.pos<<" sz "<<sig.sz<<endl;
			if((*ant).pos!=(*sig).pos){
				ans+=min(((*ant).sz-p)+2,p-(*ant).pos+1);
			}
		}
		//cout<<"ans "<<ans<<endl;
		ant = sig;
	}
	return ans;
}

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	trie arr[26];
	forn(i,n){
		string s;
		cin>>s;
		arr[int(s[0]-'a')].add(s,0,false,1);
	}
	
	forn(i,m){
		string s;
		cin>>s;
		cout<<dfs(s,&arr[int(s[0]-'a')])<<"\n";
	}
	
	
	return 0;
}
