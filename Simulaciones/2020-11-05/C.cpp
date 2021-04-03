#include <bits/stdc++.h>
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

#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
		unsigned t0, t1; t0=clock();
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll q;
	cin>>q;
	list<vector<double>> platos;
	forn(i,q){
		char ope;
		double x,y,r;
		cin>>ope;
		cin>>x>>y>>r;
		if(ope=='A'){
			bool sol=true;
			vector<double> plata;
			plata.resize(3);
			plata[0]=x;plata[1]=y;plata[2]=r;
			forall(it,platos){
				vector<double> aux=*it;
				double x2=aux[0], y2=aux[1], r2=aux[2];
				if(dist(x,y,x2,y2)<r+r2){
					sol=false;
				}
			}
			if(sol){
				platos.pb(plata);
				cout<<"Ok\n";
			}else{
				cout<<"No\n";
			}
		}else{
			bool sol=false;
			forall(it,platos){
				vector<double> aux = *it;
				if(x==aux[0] && y==aux[1] && r==aux[2]){
					sol=true;
					platos.erase(it);
					break;
				}
			}
			if(sol){
				cout<<"Ok\n";
			}else{
				cout<<"No\n";
			}
		}
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
 

