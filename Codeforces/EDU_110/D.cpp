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
vector<ll> ans;
string s;
ll k;

void ini(ll pos){
	if(pos>=pow(2,k-1)){
		if(s[pos]=='?') ans[pos]=2;
		else ans[pos]=1;
	}else{
		ini(pos*2);
		ini(pos*2+1);
		if(s[pos]=='?'){
			ans[pos]=ans[pos*2]+ans[pos*2+1];
		}else if(s[pos]=='0'){
			ans[pos]=ans[pos*2+1];
		}else if(s[pos]=='1'){
			ans[pos]=ans[pos*2];
		}
	}
	return;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>k;
	cin>>s;
	reverse(s.begin(),s.end());
	s='-'+s;
	ans.resize(sz(s)*2,1);
	ini(1);
	
	ll q;
	cin>>q;
	forn(i,q){
		
		ll idx; char c;
		cin>>idx>>c;
		
		idx=sz(s)-idx;
		s[idx]=c;
		
		for(int j=idx;j>0;j/=2){
			if(j>=pow(2,k-1)){
				if(s[j]=='?') ans[j]=2;
				else ans[j]=1;
			}else{
				if(s[j]=='?') ans[j]=ans[j*2]+ans[j*2+1];
				else if(s[j]=='0') ans[j]=ans[j*2+1];
				else ans[j]=ans[j*2];
			}
		}
		if(s[1]=='?') ans[1]=ans[2]+ans[3];
		else if(s[1]=='0') ans[1]=ans[3];
		else ans[1]=ans[2];
		cout<<ans[1]<<"\n";
	}
	
	return 0;
}




