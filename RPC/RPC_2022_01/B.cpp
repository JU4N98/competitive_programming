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
#define MAXN 900000

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

pair<int, int> sf[MAXN];
bool sacomp(int lhs, int rhs) {return sf[lhs] < sf[rhs];}

vector<int> constructSA(string& s) { // O(n log^2(n))
	int n = s.size();                   // (sometimes fast enough)
	vector<int> sa(n), r(n);
	forn(i,n) r[i] = s[i]; //r[i]: equivalence class of s[i..i+m)
	for(int m=1; m<n; m*=2) {
		//sf[i] = {r[i], r[i+m]}, used to sort for next equivalence classes
		forn(i,n) sa[i] = i, sf[i] = {r[i], i+m<n ? r[i+m] : -1};
		stable_sort(sa.begin(), sa.end(), sacomp); //O(n log(n))
		r[sa[0]] = 0;
		//if sf[sa[i]] == sf[sa[i-1]] then same equivalence class
		forr(i,1,n) r[sa[i]] = sf[sa[i]]!=sf[sa[i-1]] ? i : r[sa[i-1]];
	}
	return sa;
}

void printSA(string s, vector<int> sa, int l, int r){
	forn(i,sz(sa)){
		cout << sa[i] << "	|" ;
		forr(j,l,r+1) cout << s[j] ;
		cout << endl;
	}
}

int low(vector<int> sa, string s, string t, int i, int l, int r){
	while(l<r){
		int med = (l+r)/2;
		
		if (s[sa[med]+i]<t[i]){
			l = med+1;
		}else{
			r = med;
		}
	}
	return l;
}

int up(vector<int> sa, string s, string t, int i, int l, int r){
	while(l<r){
		int med = (l+r)/2;
		
		if (s[sa[med]+i]>t[i]){
			r = med;
		}else{
			l = med + 1;
		}
	}
	return l;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s; cin >> s;
	reverse(s.begin(),s.end());
	int ssz = sz(s);
	forn(i,ssz+10) s += '?';
	vector<int> sa = constructSA(s);
	printSA(s,sa,0,ssz);
	int n; cin >> n;
	forn(N,n){
		string t; cin >> t; int k; cin >> k;
		reverse(t.begin(),t.end());
		int l = 0, r = sz(s)+1;
		forn(i,sz(t)){
			int al = low(sa,s,t,i,l,r);
			int ar = up(sa,s,t,i,l,r);
			l = al;
			r = ar;
			//~ cout << "L: " << l << " R: " << r << endl;
		}
		if(l + k - 1 < r) cout << ssz - sa[l + k - 1] - (sz(t)-1) << endl;
		else cout << -1 << "\n";
		
	}
	
	
	return 0;
}




