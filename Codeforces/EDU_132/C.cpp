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

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	forn(T,t){
		string s; cin >> s;
		string aux = s;
		
		int co = 0, maxi = sz(s)/2;
		forn(i,sz(s)) co += s[i] == '(';
		
		int sum = 0;
		forn(i,sz(s)){
			if(s[i] == '?'){
				if(sum == 0 || (sum>0 && maxi>co)){
					sum++;
					s[i] = '(';
					co++;
				}else{
					s[i] = ')';
					sum--;
				}
			}
			else if(s[i] == '('){ sum++; }
			else if(s[i] == ')'){ sum--; }
		}
		bool uni = true;
		
		vector<int> pre(sz(s)+1);
		forn(i,sz(s)){
			pre[i+1] = s[i] == '(' ? 1 : -1;
			pre[i+1] += pre[i];
		}
		
		int r = 0; multiset<ll> in;
		forn(l,sz(s)){
			//~ cout << "A" << endl;
			while(r<sz(s) && r<=l){ 
				in.insert(pre[r+1]);
				r++;
			}
			//~ cout << "B" << endl;
			if(s[l] == '(' && aux[l] == '?'){
				while(r<sz(s) && !(s[r] == ')' && aux[r] == '?')){
					in.insert(pre[r+1]);
					r++;
				}
				if(*(in.begin())>=2){
					uni = false;
					break;
				}
			}
			//~ cout << "C" << endl;
			in.erase(in.find(pre[l+1]));
			//~ cout << "D" << endl;
		}
		
		if(uni) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




