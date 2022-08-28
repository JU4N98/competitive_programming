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
	int n; cin >> n;
	
	vector<int> ans(n);
	vector<ii>  found;
	
	forn(i,n){
		cout << "? 2 " << 1 << " " << i+1 << endl;
		int cant = 1; cin >> cant;
		
		if(cant>sz(found)){
			cout << "? 1 " << i+1 << endl;
			char car;
			cin >> car;
			found.pb({i,car-'a'});
			ans[i] = found[sz(found)-1].snd;
		}else{
			int l = 0, r = sz(found)-1;
			
			while(l<r){
				int med = (l+r+1)/2;
				cout << "? 2 " << found[med].fst+1 << " " << i+1 << endl;
				
				cin >> cant;
				if(cant == sz(found) - med){
					l = med;
				}else{
					r = med-1;
				}
			}
			
			ans[i] = found[l].snd;
			found[l].fst = i;
			sort(found.begin(),found.end());
		}
	}
	
	cout << "! ";
	forn(i,n) cout << char('a'+ans[i]);
	cout << endl;
	
	return 0;
}




