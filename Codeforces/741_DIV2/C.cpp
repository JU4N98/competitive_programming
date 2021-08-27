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

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin>>t;
	forn(T,t){
		int n; cin>>n; string s; cin>>s;
		ii p1,p2;
		if(n==2){
			if(s[0]=='1') p2 = {2,2}, p1 = {1,1};
			else p2 = {1,1}, p1 = {2,2};
		}else{
			forr(i,(n/2),n) if(s[i]=='0'){
				p1.fst=i-(n/2)+1;
				p1.snd=i;
				p2.fst=i-(n/2)+1;
				p2.snd=i+1;
			}
			forr(i,(n/2)-1,n-2) if(s[i+1]=='1' && s[i+2]=='1'){
				p1.fst=i-(n/2)+1;
				p1.snd=i;
				p2.fst=i-(n/2)+1;
				p2.snd=i+2;
			}
		}
		cout<<p1.fst<<" "<<p1.snd<<" "<<p2.fst<<" "<<p2.snd<<"\n";
	}
	
	return 0;
}




