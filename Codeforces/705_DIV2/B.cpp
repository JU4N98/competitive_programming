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
typedef pair<ll,ll> ii;

ll inv(ll in){
	switch(in){
		case 0:
			return 0;
		break;
		case 1:
			return 1;
		break;
		case 2:
			return 5;
		break;
		case 5:
			return 2;
		break;
		case 8:
			return 8;
		break;
	}
}

string sal(ll in){
	string sali = "00";
	sali[0]+=(in/10)%10;
	sali[1]+=in%10;
	return sali;
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
	ll val[5] = {0,1,2,5,8};
	vector<ii> tiempos, tiemposi;
	forn(i,5){
		forn(i2,5){
			forn(i3,5){
				forn(i4,5){
					tiempos.pb({val[i]*10+val[i2],val[i3]*10+val[i4]});
					tiemposi.pb({inv(val[i4])*10+inv(val[i3]),inv(val[i2])*10+inv(val[i])});
				}
			}
		}
	}
	cin>>t;
	forn(T,t){
		ll h,m;
		cin>>h>>m;
		string s;
		cin>>s;
		set<ii> tiemposval;
		ii ini = {(s[0]-'0')*10+(s[1]-'0'),(s[3]-'0')*10+(s[4]-'0')};
		forn(i,tiempos.size()){
			if(tiempos[i].fst<h && tiempos[i].snd<m && tiemposi[i].fst<h && tiemposi[i].snd<m) tiemposval.insert(tiempos[i]);
		}
		ii ans;
		if(tiemposval.lower_bound(ini)==tiemposval.end()) ans = {0,0};
		else ans = *(tiemposval.lower_bound(ini));
		cout<<sal(ans.fst)<<":"<<sal(ans.snd)<<endl;
	}
	
	
	return 0;
}




