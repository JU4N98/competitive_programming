#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it = v.begin(); it!=v.end(); it++)
#define fst first
#define snd second
#define pb push_back
#define ll long long
//#define ANARAP
vector<vector<ll>> mat;
vector<string> ans;

void resolver(ll cant0, ll cant1, ll x[4],ll y[4]){
	string aux;
	forn(j,4){
			if(cant0>0 && mat[x[j]][y[j]]==0){
				aux+=to_string(x[j]+1)+" "+to_string(y[j]+1)+" ";
				mat[x[j]][y[j]]=1;
				cant0--;
			}else if(cant1>0 && mat[x[j]][y[j]]==1){
				aux+=to_string(x[j]+1)+" "+to_string(y[j]+1)+" ";
				mat[x[j]][y[j]]=0;
				cant1--;
			}
	}
	ans.pb(aux);
}

void solve(ll x[4],ll y[4]){
	ll sum=0;
	forn(j,4){
		sum+=mat[x[j]][y[j]];
	}
	if(sum==4){
		ll cant0=0, cant1=3;
		resolver(cant0,cant1,x,y);
		sum=1;
	}
	if(sum==1){
		ll cant0=2, cant1=1;
		resolver(cant0,cant1,x,y);
		sum=2;
	}
	if(sum==2){
		ll cant0=2, cant1=1;
		resolver(cant0,cant1,x,y);
		sum=3;
	}
	if(sum==3){
		ll cant0=0, cant1=3;
		resolver(cant0,cant1,x,y);
		sum=0;
	}
}


int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n,m;
		cin>>n>>m;
		mat.resize(n);
		forn(j,n) mat[j].resize(m);
		forn(j,n){
			string s;
			cin>>s;
			forn(k,m) mat[j][k]=s[k]-'0';
		}
		for(int j=0;j<n;j+=2){
			for(int k=0;k<m;k+=2){
				ll x[4], y[4];
				if(j==n-1){
					if(k==m-1){
						x[0]=j;x[1]=j-1;x[2]=j,x[3]=j-1;
						y[0]=k;y[1]=k;y[2]=k-1,y[3]=k-1;
					}else{
						x[0]=j;x[1]=j-1;x[2]=j,x[3]=j-1;
						y[0]=k;y[1]=k;y[2]=k+1,y[3]=k+1;
					}
				}else{
					if(k==m-1){
						x[0]=j;x[1]=j;x[2]=j+1,x[3]=j+1;
						y[0]=k;y[1]=k-1;y[2]=k,y[3]=k-1;
					}else{
						x[0]=j;x[1]=j;x[2]=j+1,x[3]=j+1;
						y[0]=k;y[1]=k+1;y[2]=k,y[3]=k+1;
					}
				}
				solve(x,y);
				
			}
		}
		cout<<ans.size()<<"\n";
		forn(l,ans.size()){
			cout<<ans[l]<<"\n";
		}
		ans.clear();
		mat.clear();
	}
	
	
	return 0;
}
