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
	
	int t,n,q;
	cin>>t>>n>>q;
	forn(T,t){
		cout<<1<<" "<<2<<" "<<3<<endl;
		vector<int> in;
		int median;
		cin>>median;
		if(median==-1) return 0;
		if(median==1){ in.pb(2); in.pb(1); in.pb(3);}
		if(median==2){ in.pb(1); in.pb(2); in.pb(3);}
		if(median==3){ in.pb(2); in.pb(3); in.pb(1);}
		int num = 4;
		while(in.size()!=n){
			int l = 0, r=in.size()-1, med = (l+r)/2,pos;
			while(l+1<r){
				med=(l+r)/2;
				//cout<<"l "<<l<<" med "<<med<<" r "<<r<<endl;
				cout<<in[l]<<" "<<num<<" "<<in[med]<<endl;
				cin>>median;
				if(median==-1) return 0;
				if(median==in[l]){
					pos=l;
					break;
				}else if(median==num){
					r=med;
				}else{
					l=med;
				}
			}
			if(l+1==r){
				//cout<<"l "<<l<<" med "<<med<<" r "<<r<<endl;
				cout<<in[l]<<" "<<num<<" "<<in[r]<<endl;
				cin>>median;
				if(median==-1) return 0;
				if(median==in[l]) pos=l;
				if(median==num) pos = r;
				if(median==in[r]) pos=r+1;
			}
			vector<int> aux(0);
			//cout<<"pos "<<pos<<endl;
			forn(i,pos) aux.pb(in[i]);
			aux.pb(num);
			forr(i,pos,in.size()) aux.pb(in[i]);
			//cout<<"aux ";
			//forn(i,aux.size()) cout<<aux[i]<<" ";
			//cout<<endl;
			in=aux;
			num++;
		}
		forn(i,in.size()) cout<<in[i]<<" ";
		cout<<endl;
		int resp;
		cin>>resp;
		if(resp==-1) return 0;
	}
	
	return 0;
}




