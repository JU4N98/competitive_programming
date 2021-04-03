#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll n;
	cin>>n;
	vector<ll> in;
	queue<ll> q;
	in.resize(n);
	vector<pair<ll,ll>> ans;
	forn(i,n){
		cin>>in[i];
		if(in[i]==1) q.push(i);
	}
	
	ll fil=0; bool sol=true;
	forn(i,n){
		switch(in[i]){
			case 1:
				ans.pb({fil,i});
				fil++;
			break;
			case 2:
				while(!q.empty() && q.front()<i) q.pop();
				if(q.empty()){
					sol=false;
					break;
				}else{
					ans.pb({fil,i});
					ans.pb({fil,q.front()});
					in[q.front()]=0;
					q.pop();
					fil++;
				}
			break;
			case 3:
				ll j=i+1;
				while(j<n && in[j]==0) j++;
				if(j==n){
					sol=false;
					break;
				}
				ans.pb({fil,i});
				ans.pb({fil,j});
				fil++;
			break;
			dbg(in[i])
			dbg(sol)
		}
	}
	
	if(sol){
		cout<<ans.size()<<"\n";
		forn(i,ans.size()) cout<<ans[i].fst+1<<" "<<ans[i].snd+1<<"\n";
	}else{
		cout<<"-1\n";
	}
	
	return 0;
}
