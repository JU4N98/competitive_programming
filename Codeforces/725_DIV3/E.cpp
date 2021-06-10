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
		//~ cout<<T<<endl;
		ll n;
		cin>>n;
		map<string,pair<string,ll>> m;
		ll fin;
		forn(i,n){
			string var,ope,term;
			cin>>var;
			cin>>ope;
			cin.ignore();
			getline(cin,term);
			//~ cout<<var<<" "<<ope<<" "<<term<<endl;
			if(ope==":="){
				string cur=""; ll sum=0;
				forn(j,sz(term)) if(j+3<sz(term) && term[j]=='h' && term[j+1]=='a' && term[j+2]=='h' && term[j+3]=='a') sum++;
				if(sz(term)>3){
					forn(j,3) if(term[j]!='?') cur+=term[j];
					cur+="???";
					dforn(j,3) if(term[sz(term)-1-j]!='?') cur+=term[sz(term)-1-j];
				}else cur=term;
				m[var]={cur,sum};
			}else{
				stringstream sterm(term);
				string aux,curr="",term="";
				ll sum=0;
				while(sterm>>skipws>>aux) if(aux!="+"){ term+=m[aux].fst; sum+=m[aux].snd;}
				//~ cout<<term<<endl;
				forn(j,sz(term)) if(j+3<sz(term) && term[j]=='h' && term[j+1]=='a' && term[j+2]=='h' && term[j+3]=='a') sum++;
				if(sz(term)>3){
					forn(j,3) if(term[j]!='?') curr+=term[j];
					curr+="???";
					dforn(j,3) if(term[sz(term)-1-j]!='?') curr+=term[sz(term)-1-j];
				}else curr=term;
				m[var]={curr,sum};
				//~ cout<<"curr "<<curr<<" "<<sum<<endl;
			}
			if(i==n-1){
				//~ cout<<m[var].fst<<endl;
				fin=m[var].snd;
			}
		}
		cout<<fin<<endl;
	}
	
	return 0;
}




