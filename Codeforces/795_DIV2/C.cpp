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
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int ones = 0;
		forn(i,n) if(s[i]=='1') ones++;
		
		int sub = 0;
		if(ones>0){
			int pos = n-1;
			dforn(i,n) if(s[i]=='1'){
				pos = i;
				break;
			}
			if(k >= (n-(pos+1))){ 
				sub += 10; 
				k -= (n-(pos+1));
			}
			
			if(sub==0 || ones>1){
				pos = 0;
				forn(i,n) if(s[i]=='1'){
					pos = i;
					break;
				}
				
				if(k>=pos) sub++;
			}
		}
		
		cout << ones*11 - sub << "\n";
	}
	
	return 0;
}




