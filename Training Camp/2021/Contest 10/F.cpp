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
typedef pair<ll,ll> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, tmax; cin>>n>>tmax;
	vector<vector<ii>> dp(n,vector<ii>(tmax+1));
	vector<vector<bool>> us(n,vector<bool>(tmax+1));
	vector<pair<ii,ll>> prob(n);
	vector<ll> ans;
	forn(i,n){
		int ti,pi; cin>>ti>>pi;
		prob[i]={{pi,ti},i+1};
	}
	sort(prob.begin(),prob.end(),[&](pair<ii,ll> a, pair<ii,ll> b){return a.fst.snd*b.fst.fst<a.fst.fst*b.fst.snd;});
	//~ forn(i,n) cout<<prob[i].snd<<" ";
	//~ cout<<endl;
	
	forn(ta,tmax+1){
		ll ti = prob[0].fst.snd, pi = prob[0].fst.fst;
		if(ta>=ti){ dp[0][ta]=mp(pi,-ta*pi); us[0][ta]=true;}
	}
	//~ cout<<"completa n-1"<<endl;
	forr(i,1,n){
		forn(ta,tmax+1){
			ll ti = prob[i].fst.snd, pi = prob[i].fst.fst;
			dp[i][ta]=dp[i-1][ta];
			if(ta>=ti && dp[i][ta]<mp(dp[i-1][ta-ti].fst+pi,dp[i-1][ta-ti].snd-ta*pi)){
				dp[i][ta]=mp(dp[i-1][ta-ti].fst+pi,dp[i-1][ta-ti].snd-ta*pi);
				us[i][ta]=true;
			}
		}
	}
	
	//~ forn(ta,tmax+1){
		//~ forr(i,1,n){
			//~ cout<<dp[i][ta].fst<<"	";
		//~ }
		//~ cout<<"\n";
	//~ }
	
	//~ cout<<"completa dp"<<endl;
	ii ia={n-1,tmax};
	//~ cout<<dp[ia.fst][ia.snd].fst<<" "<<dp[ia.fst][ia.snd].snd<<endl;
	dforn(i,tmax+1) if(dp[n-1][ia.snd]<dp[n-1][i]) ia.snd=i;
	//~ cout<<ia.fst<<" "<<ia.snd<<endl;
	//~ cout<<dp[ia.fst][ia.snd].fst<<" "<<dp[ia.fst][ia.snd].snd<<endl;
	while(ia.fst>-1){
		if(us[ia.fst][ia.snd]){
			ans.pb(prob[ia.fst].snd);
			ia.snd-=prob[ia.fst].fst.snd;
		}
		ia.fst-=1;
	}
	reverse(ans.begin(),ans.end());
	
	cout<<sz(ans)<<"\n";
	forn(i,sz(ans)) cout<<ans[i]<<" ";
	cout<<"\n";
	
	return 0;
}




