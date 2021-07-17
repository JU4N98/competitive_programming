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
typedef pair<int,int> ii;

vector<set<ii>> ans(100);
vector<int> prof(100,100);

void calc(set<int> &num, set<ii> &ansi){
	int u = *(num.rbegin());
	if(sz(num)>10) return;
	forall(i,num){
		int v = *i + u;
		if(v<=100){
			num.insert(v);
			ansi.insert({u,*i});
			if(sz(ansi)<prof[v-1]){
				ans[v-1]=ansi;
				prof[v-1]=sz(ansi);
			}
			calc(num,ansi);
			num.erase(v);
			ansi.erase({u,*i});
		}
	}
}

int main()
{
	//~ #ifdef LASCALONETA
		//~ freopen("input.in", "r", stdin);
	//~ #endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	set<int> num;
	set<ii> ansi;
	num.insert(1);
	prof[0]=1;
	calc(num,ansi);
	ofstream of;
	of.open("ans.txt");
	forn(i,100){
		of<<"{\"";
		forall(it,ans[i]){
			of<<"1 "<<it->fst<<"\\n";
			of<<"1 "<<it->snd<<"\\n";
		}
		of<<"\"},\n";
	}
	of.close();
	
	return 0;
}

