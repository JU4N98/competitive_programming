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
	ll t;
	cin>>t;
	forn(T,t){
		ll a,b;
		string s;
		cin>>a>>b;
		cin>>s;
		ll n=s.size();
		bool ok=true;
		forn(i,(n+1)/2){
			if(s[i]=='?' && s[n-i-1]!='?') s[i]=s[n-i-1];
			if(s[i]!='?' && s[n-i-1]=='?') s[n-i-1]=s[i];
			if((s[i]=='1' && s[n-i-1]=='0') || (s[i]=='0' && s[n-i-1]=='1')) ok=false;
		}
		ll cantp = 0;
		forn(i,n){
			if(s[i]=='0') a--; else if(s[i]=='1') b--; else cantp++; 
		}

		if(ok){
			if(a>=0 && b>=0 && cantp==a+b){
				if(n%2==0 && (a%2==1 || b%2==1)){
					cout<<"-1\n";
					continue;
				}else if(n%2==1 && a%2==1 && b%2==1){
					cout<<"-1\n";
					continue;
				}
				forn(i,(n+1)/2){
					if(i!=n/2 || n%2==0){
						if(s[i]=='?'){
							if(a>1){
								a-=2;
								s[i]='0';
								s[n-i-1]='0';
							}else{
								b-=2;
								s[i]='1';
								s[n-i-1]='1';
							}
						}
					}else{
						if(s[i]=='?'){
							if(a>0){
								s[i]='0';
							}else{
								s[i]='1';
							}
						}
					}
				}
				cout<<s<<"\n";
			}else{
				cout<<"-1\n";
			}
		}else{
			cout<<"-1\n";
		}
	}
	return 0;
}




