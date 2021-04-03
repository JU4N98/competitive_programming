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
#define ANARAP

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

ll calc(ll in, ll k){
	if(in%k==0) in=0; else in = k-(in%k);
	return in;
}

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
		ll n,k;
		string s;
		cin>>n>>k;
		cin>>s;
		ll ans=-1;
		vector<ll> cuenta(26,0),cuentaf;
		if(n%k==0){
			bool sol=false;
			
			if(sol) cout<<s<<"\n";
			else{
				forn(i,s.size()){
					ll cant=0;
					if(s[i]!='z'){
						forn(i,26) if((i-1)==s[i]-'a') cant+= calc(cuenta[i]+1,k); else cant+= calc(cuenta[i],k);
						if(cant<=(n-i-1)){
							ans=i;
							cuentaf=cuenta;
							cuentaf[s[i]-'a'+1]++;
						}
					}
					cuenta[s[i]-'a']++;
				}
				if(ans==-1){
					forn(i,s.size()) cout<<"z";
					cout<<"\n";
				}else{
					forn(i,ans){
						cout<<s[i];
					}
					cout<<(s[ans]+1);
					forn(i,26){
						char cha = char ('a'+i);
						forn(j,calc(cuentaf[i],k)) cout<<cha;
					}
					cout<<"\n";
				}
			}
		}else{
			cout<<-1<<"\n";
		}
	}
	
	return 0;
}




