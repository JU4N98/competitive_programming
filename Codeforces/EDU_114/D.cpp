#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define foraint(it,v) for(auto it=v.begin();it!=v.end();it++)
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
int n;
vector<vector<ii>> slots;

string id1(vector<int> &arr){
	string aid="";
	vector<int> arra(n);
	forn(i,n) arra[i]=arr[i];
	forn(i,n){
		forn(j,6){
			aid+= char('0'+arra[i]%10);
			arra[i]/=10;
		}
	}
	return aid;
}

string id(vector<int> &arr){
	string aid="";
	vector<int> arra(n);
	forn(i,n) arra[i]=slots[i][arr[i]].snd;
	forn(i,n){
		forn(j,6){
			aid+= char('0'+arra[i]%10);
			arra[i]/=10;
		}
	}
	return aid;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	slots.resize(n);
	forn(i,n){
		int ci; cin>>ci; slots[i].resize(ci);
		forn(j,ci){
			cin>>slots[i][j].fst;
			slots[i][j].snd=j;
		}
		sort(slots[i].begin(),slots[i].end());
		reverse(slots[i].begin(),slots[i].end());
	}
	
	set<string> banned;
	int m; cin>>m;
	vector<int> aux(n);
	forn(i,m){
		forn(j,n){ cin>>aux[j];aux[j]--;}
		banned.insert(id1(aux));
	}
	
	vector<vector<int>> arr;
	set<string> s;
	multiset<ii> pq;
	
	int iniv=0;
	vector<int> ini(10);
	forn(i,n){
		ini[i]=0;
		iniv+=slots[i][0].fst;
	}
	arr.pb(ini);
	pq.insert({-iniv,0});
	s.insert(id(ini));
	
	vector<int> ans;
	bool fou=false;
	while(!fou){
		ii act = *(pq.begin());
		pq.erase(pq.begin());
		
		if(banned.find(id(arr[act.snd]))==banned.end()){
			ans=arr[act.snd];
			fou=true;
		}
		
		forn(i,n){
			if(sz(slots[i])==arr[act.snd][i]+1) continue;
			arr[act.snd][i]++;
			string idi = id(arr[act.snd]);
			if(s.find(idi)==s.end()){
				arr.pb(arr[act.snd]);
				int ival=0;
				forn(j,n){
					ival+=slots[j][arr[act.snd][j]].fst;
				}
				pq.insert({-ival,sz(arr)-1});
				s.insert(idi);
			}
			arr[act.snd][i]--;
		}
		
	}
	forn(i,n) cout<<slots[i][ans[i]].snd+1<<" ";
	cout<<"\n";
	
	return 0;
}




