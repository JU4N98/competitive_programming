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
	
	ll pos=1,neg=0;
	string in; cin>>in; cin>>in;
	string ope="";
	while(in!="="){
		if(in=="+"){ 
			pos++; 
			ope+="+";
		}else{
			neg++;
			ope+="-";
		}
		cin>>in; cin>>in;
	}
	cin>>in; ll n = 0; forn(i,sz(in)){ n*=10; n+=in[i]-'0';}
	//~ cout<<pos<<" "<<neg<<"\n"; cout<<n<<"\n";
	
	ll maxi = pos*n - neg, mini = pos-neg*n;
	if(n<=maxi && n>=mini){
		cout<<"Possible\n";
		maxi = -neg + pos;
		vector<ll> vp(pos,1),vn(neg,1);
		forn(i,pos)
			if(maxi<n){
				vp[i] = min(n-(maxi-1),n);
				maxi += (vp[i]-1);
			}
		forn(i,neg)
			if(maxi>n){
				vn[i] = min((maxi+1)-n,n);
				maxi -= (vn[i]-1);
			}
		cout<<vp[0]<<" "; ll pi=1,ni=0;
		forn(i,sz(ope)){
			cout<<ope[i]<<" ";
			if(ope[i]=='+'){
				cout<<vp[pi]<<" ";
				pi++;
			}else{
				cout<<vn[ni]<<" ";
				ni++;
			}
		}
		cout<<"= "<<n<<"\n";
	}else{
		cout<<"Impossible\n";
	}
	
	
	return 0;
}




