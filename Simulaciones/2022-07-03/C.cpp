#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<int> parse(string c){
	bool ant = true;
	bool neg = false;
	int idx = 0;
	vector<int> hc(1);
	forn(j,sz(c)){
		if(c[j] == '!'){
			neg = true;
		}else if(c[j] == ' '){
			if(neg) hc[idx] *= -1;
			if(ant) hc[idx] *= -1;
			
			if(hc[idx] != 0){
				hc.pb(0);
				idx++;
			}
			neg = false;
		}else if(c[j] == '-'){
			j++;
			ant = false;
		}else{
			hc[idx]*=10;
			hc[idx]+=(c[j]-'0');
		}
	}
	if(neg) hc[idx] *= -1;
	if(ant) hc[idx] *= -1;
	if(sz(hc) == 1) hc[0] *= -1;
	
	return hc;
}

void deleteClause(vector<set<int>> &form, set<int> &pos){
	forall(it,pos){
		int szi = sz(form[*it]);
		while(szi--) form[*it].erase(form[*it].begin());
	}
}

void deleteLiteral(queue<int> &q, vector<set<int>> &form, set<int> &neg, int act){
	forall(it,neg){
		form[*it].erase(act);
		
		if(sz(form[*it]) == 1){
			q.push(*(form[*it].begin()));
			form[*it].erase(form[*it].begin());
		}
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
	
	int n,m; cin >> n >> m;
	
	vector<set<int>> form(n);
	vector<set<int>> neg(m);
	vector<set<int>> pos(m);
	
	cin.ignore();
	forn(i,n){
		string c; 
		getline(cin,c);
		vector<int> hc = parse(c);
		
		set<int> toAdd;
		forn(j,sz(hc)){
			toAdd.insert(hc[j]);
			if(hc[j]<0) neg[abs(hc[j])-1].insert(i);
			else if(hc[j]>0) pos[hc[j]-1].insert(i);
		}
		form[i] = toAdd;
	}
	
	vector<int> ans(m);
	queue<int> q;
	bool conflict = false;
	forn(i,sz(form)){ 
		if(sz(form[i]) == 1){
			int act = *(form[i].begin());
			q.push(act);
		}
	}
		
	while(!q.empty() && !conflict){
		int act = q.front(); q.pop();
		
		if(ans[abs(act)-1] != 0){
			if(ans[abs(act)-1] != act) conflict = true;
			continue;
		} else ans[abs(act)-1] = act;
		
		if(act < 0){
			deleteClause(form,neg[abs(act)-1]);
			deleteLiteral(q,form,pos[abs(act)-1],-act);
		}else{
			deleteClause(form,pos[abs(act)-1]);
			deleteLiteral(q,form,neg[abs(act)-1],-act);
		}
	}
	
	if(conflict) cout << "conflict\n";
	else{
		forn(i,sz(ans)) cout << (ans[i]<=0? 'F' : 'T');
		cout << "\n";
	}
	
	return 0;
}
