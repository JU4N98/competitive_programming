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

ll bs1(ll l,ll r,ll x,ll g){
	ll med =(l+r)/2;;
	while(l<r){
		med=(l+r)/2;
		if(med*g+g<=x && (med+1)*g+g>x){
			r=l;
		}else if(med*g+g<=x && (med+1)*g+g<=x){
			l=med+1;
		}else if(med*g+g>x && (med+1)*g+g>x){
			r=med-1;
		}
	}
	return med;
}

/*
ll bs2(ll l,ll r,ll x,ll n){
	ll med = (l+r)/2;;
	while(l<r){
		med = (l+r)/2;
		if(n*med+med<=x && n*(med+1)+med+1<=x){
			l=med+1;
		}else if(n*med+med<=x && n*(med+1)+med+1>x){
			r=l;
		}else if(n*med+med>x && n*(med+1)+med+1>x){
			r=med-1;
		}
		cout<<l<<" "<<r<<endl;
	}
	return med;
}
*/
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
		ll x,y;
		cin>>x>>y;
		ll sqr = (ll) floor(sqrt(x));
		
		if(sqr>=y){
			cout<<(y*(y-1))/2<<"\n";
		}else{
			cout<<"B"<<endl;
			ll ans = (sqr*(sqr-1))/2;
			ll l=sqr+1,la=l,r=y+1,med=(l+r)/2,cant=max(sqr-1,1LL);
			
			cout<<cant<<endl;
			while(cant>0){
				med=(l+r)/2;
				while(l<r){
					med=(l+r)/2;
					cout<<"("<<l<<","<<med<<","<<r<<")"<<endl;
					if(med*cant+cant<=x && (med+1)*cant+cant>x){
						r=l;
					}else if(med*cant+cant<=x && (med+1)*cant+cant<=x){
						l=med+1;
					}else if(med*cant+cant>x && (med+1)*cant+cant>x){
						r=med;
					}
					
				}
				if(med*cant+cant<=x && (med+1)*cant+cant){
					cout<<med-la<<endl;
					ans+=cant*(med-la+1);
					la=med+1;
					l=med+1;
				}else{
					l=la;
				}
				//bool b =med*cant+cant ;
				//cout<<"("<<b <<")"<<endl;
				r=y+1;
				cant--;
			}
			cout<<ans<<endl;
		}
		cout<<"========\n";
	}

	
	
	return 0;
}



