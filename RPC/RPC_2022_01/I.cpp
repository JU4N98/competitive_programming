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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<int> parse(string s){
	vector<int>  ans;
	int act = -1;
	
	forn(i,sz(s)){
		if(s[i] == ','){ ans.pb(act); act = -1;}
		else if(s[i] == '-'){
			int nxt = 0, pos=i;
			forr(j,i+1,sz(s)){
				pos=j;
				if(s[j] == ',') break;
				else nxt = nxt * 10 + (s[j]-'0');
			}
			forr(j,act,nxt+1) ans.pb(j);
			act = -1;
			i=pos;
		}else {
			if (act == -1) act = 0;
			act = act*10 + (s[i]-'0');
		}
	}
	
	if( act != -1) ans.pb(act);
	return ans;
}

void print(vector<int> ans){
	forn(i,sz(ans)) cout << ans[i] <<  " ";
	cout << "\n";
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	
	vector<bool> sec(86400);
	
	int ans1 = 0, ans2 = 0;
	forn(T,t){
		string h,m,s; cin >> h >> m >> s;
		
		vector<int> hs,ms,ss;
		
		if(h == "*") forn(i,24) hs.pb(i);
		else hs = parse(h);
		//~ print(hs);
		if(m == "*") forn(i,60) ms.pb(i);
		else ms = parse(m);
		//~ print(ms);
		if(s == "*") forn(i,60) ss.pb(i);
		else ss = parse(s);
		//~ print(ss);
		forn(i,sz(hs)){
			forn(j,sz(ms)){
				forn(k,sz(ss)){
					sec[hs[i]*3600+ms[j]*60+ss[k]]=true;
					ans2 ++;
				}
			}
		}
	}
	
	forn(i,86400) ans1 += sec[i];
	cout << ans1 << " " << ans2 << "\n";
	
	return 0;
}




