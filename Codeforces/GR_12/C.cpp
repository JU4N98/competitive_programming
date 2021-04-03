#include<bits/stdc++.h>
using namespace std;

#define forr(a,b,c) for(int a=b;a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it = v.begin(); it!=v.end(); it++)
#define fst first
#define snd second
#define pb push_back
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(i,t){
		ll n;
		cin>>n;
		vector<string> mat(n);
		forn(j,n){
			cin>>mat[j];
		}
		
		forn(j,n){
			ll count[2]={0,0};
			forn(k,n){
				if(mat[j][k]=='X'){
					count[0]++;
					count[1]=0;
				}else if(mat[j][k]=='O'){
					count[1]++;
					count[0]=0;
				}
				if(count[0]==3){
					mat[j][k]='O';
					count[1]=1;
					count[0]=0
				}else if (count[1]==3){
					mat[j][k]='X';
					count[1]=0;
					count[0]=1;
				}
			}
			count[0]=0; count[1]=0;
			forn(k,n){
				if(mat[k][j]=='X'){
					count[0]++;
					count[1]=0;
				}else if(mat[k][j]=='O'){
					count[1]++;
					count[0]=0;
				}
				if(count[0]==3){
					mat[k-1][j]='O';
					count[1]=
				}else if (count[1]==3){
					mat[k-1][j]='X';
				}
			}
		}
		
		while(!filas.empty()){
			ll x,y;
			if(!columnas.empty()){
				x = filas.front(), y=columnas.front();
				filas.pop();columnas.pop();
			}else{
				x = filas.front(); y = 0;
				filas.pop();
			}
			if(mat[x][y]=='X') mat[x][y]='O'; else mat[x][y]='X';
		}
		
		while(!columnas.empty()){
			ll y = columnas.front(); ll x = 0;
			columnas.pop();
			if(mat[x][y]=='X') mat[x][y]='O'; else mat[x][y]='X';
		}
		
		forn(j,n){
			cout<<mat[j]<<"\n";
		}
		mat.clear();
	}
	
	
	
	return 0;
}
