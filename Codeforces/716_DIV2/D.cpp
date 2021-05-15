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
	#define MAXN 10000
#else
	#define MAXN 300010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
int block_size;
int a[MAXN],f[MAXN],cf[MAXN],maxi;

struct query{
	int l,r,idx;
	bool operator<(const query &other){
		return make_pair(l/block_size,r)<make_pair(other.l/block_size,other.r);
	}
};
/*
bool comp(const query &a, const query &b){
	return make_pair(a.l/block_size,a.r)<make_pair(b.l/block_size,b.r);
}
*/
void add(int i){
	//cout<<"add "<<i<<" \n";
	i=a[i];
	cf[f[i]]--;
	f[i]++;
	if(!cf[f[i]])maxi=max(maxi,f[i]);
	cf[f[i]]++;
}

void remove(int i){
	//cout<<"remove "<<i<<" \n";
	i=a[i];
	if(cf[f[i]]==1 && maxi==f[i]) maxi--;
	cf[f[i]]--;
	f[i]--;
	cf[f[i]]++;
}

vector<int> mo(vector<query> q){
	vector<int> ans(q.size());
	int curr=0,curl=0;
	sort(q.begin(),q.end());
	for(query qi: q){
		while(curl>qi.l){
			add(--curl);
		}
		while(curr<qi.r){
			add(curr++);
		}
		while(curl<qi.l){
			//cout<<"remove l\n";
			remove(curl++);
		}
		while(curr>qi.r){
			//cout<<"remove r\n";
			remove(--curr);
		}
		ans[qi.idx]=maxi;
	}
	return ans;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,q;
	cin>>n>>q;
	forn(i,n) cin>>a[i];
	vector<query> qu;
	forn(i,q){
		query qi;
		cin>>qi.l>>qi.r;
		qi.l--;
		qi.idx=i;
		qu.pb(qi);
	}
	block_size=int(ceil(sqrt(n)));
	vector<int> ans = mo(qu);
	
	forn(i,q){
		int lar = qu[i].r-qu[i].l;
		//if(n==300000 && q==300000) cout<<qu[i].l<<" "<<qu[i].r<<" "<<ans[i]<<endl;
		cout<<1+max(0,ans[i]-(lar-ans[i])-1)<<"\n";
	}
	
	return 0;
}




