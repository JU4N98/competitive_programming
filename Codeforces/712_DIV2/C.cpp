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
		ll n;
		cin>>n;
		string s;
		cin>>s;
		string a="",b;
		bool sol=true;
		ll count=0;
		forn(i,n) if(s[i]=='0') count++;
		if(count%2==1 || s[0]=='0' || s[n-1]=='0') sol=false;
		
		bool ite=true;
		forn(i,n){
			if(s[i]=='0'){
				if(ite){
					a+="(";
					b+=")";
				}else{
					a+=")";
					b+="(";
				}
				ite = !ite;
			}else{
				a+="?";
				b+="?";
			}
		}
		ll aux=n-count;
		count=0;
		forn(i,n){
			if(a[i]=='?'){
				if(count<aux/2){
					a[i]='(';
					b[i]='(';
				}else{
					a[i]=')';
					b[i]=')';
				}
				count++;
			}
		}
		
		if(!sol) cout<<"NO\n";
		else{
			cout<<"YES\n"<<a<<"\n"<<b<<"\n";
		}
	}
	
	return 0;
}




