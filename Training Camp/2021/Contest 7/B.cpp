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

struct frac{
	ll p,q;
	frac(int p=0,int q=1):p(p),q(q) {norm();}
	void norm()
	{
		int a=__gcd(q,p);
		if(a) p/=a, q/=a;
		else q=1;
		if (q<0) q=-q, p=-p;
	}
	frac operator+(const frac& o)
	{
		int a=__gcd(o.q,q);
		return frac(p*(o.q/a)+o.p*(q/a),q*(o.q/a));
	}
	frac operator-(const frac& o)
	{
		int a=__gcd(o.q,q);
		return frac(p*(o.q/a)-o.p*(q/a),q*(o.q/a));
	}
	frac operator*(frac o)
	{
		int a=__gcd(o.p,q), b=__gcd(p,o.q);
		return frac((p/b)*(o.p/a),(q/a)*(o.q/b));
	}
	frac operator/(frac o)
	{
		int a=__gcd(o.q,q), b=__gcd(p,o.p);
		return frac((p/b)*(o.q/a),(q/a)*(o.p/b));
	}
	bool operator<(const frac &o) const{return p*o.q < o.p*q;}
	bool operator==(frac o){return p==o.p&&q==o.q;}
};

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,w; cin>>n>>w;
	vector<ii> arr(n);
	forn(i,n) cin>>arr[i].fst>>arr[i].snd;
	set<pair<frac,ii>> s;
	forn(i,n){
		if(frac(arr[i].fst,1)<frac(arr[i].snd,2) || frac(arr[i].fst,1)==frac(arr[i].snd,2)) s.insert({frac(arr[i].fst,1),{0,i}});
		else s.insert({frac(arr[i].fst,2),{1,i}});
	}
	
	vector<ll> resp(n);
	vector<bool> visi1(n,false),visi2(n,false);
	ll sum=0, ans=0,max2=-1;
	while(!s.empty() && sum<w){
		pair<frac,ii> p = *s.begin();
		s.erase(s.begin());
		ll idx = p.snd.snd, stars = p.snd.fst;
		if(stars==0){
			ans+=arr[idx].fst;
			sum+=1;
			s.insert({frac(arr[idx].snd-arr[idx].fst,1),{2,idx}});
			visi1[idx]=true;
			resp[idx]=1;
		}else if(stars==1){
			ans+=arr[idx].snd;
			sum+=2;
			visi2[idx]=true;
			max2 = idx;
			resp[idx]=2;
		}else{
			ans+=arr[idx].snd-arr[idx].fst;
			sum+=1;
			visi2[idx]=true;
			max2=idx;
			resp[idx]=2;
		}
	}
	if(sum>w){
		ll ahorro = 0, tipo=-1,idx=-1;
		forn(i,n){
			if(visi1[i] && !visi2[i]){
				if(ahorro<arr[i].fst){
					tipo=0;
					idx=i;
					ahorro=arr[i].fst;
				}
			}
			if(!visi1[i] && !visi2[i] && max2!=-1){
				if(ahorro<arr[max2].snd-arr[i].fst){
					tipo=1;
					idx=i;
					ahorro=arr[max2].snd-arr[i].fst;
				}
			}
			if(!visi1[i] && visi2[i]){
				if(ahorro<arr[i].snd-arr[i].fst){
					tipo=2;
					idx=i;
					ahorro=arr[i].snd-arr[i].fst;
				}
			}
		}
		ans-=ahorro;
		if(tipo==0){
			resp[idx]=0;
		}
		if(tipo==1){
			resp[max2]=0;
			resp[idx]=1;
		}
		if(tipo==2){
			resp[idx]=1;
		}
	}
	cout<<ans<<"\n";
	forn(i,n) cout<<resp[i];
	cout<<"\n";
	
	
	return 0;
}




