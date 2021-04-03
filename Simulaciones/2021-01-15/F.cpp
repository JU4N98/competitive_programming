
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
#define ANARAP
#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;

vector<int> g[3002];

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
	
	int n; cin >> n; 
	vector<ii> point(n), ang(n);
	forn(i,n) cin >> point[i].fst >> point[i].snd >> ang[i].fst >> ang[i].snd;

	forn(i,n){
		int aux = ang[i].fst+ang[i].snd;
		int aux2 = ang[i].fst-ang[i].snd;
		ang[i] = mp(aux, aux2);
	
		//~ cout << ang[i].fst << " " << ang[i].snd << endl;
		//~ if(ang[i].fst <=90 || ang[i].fst >180){
			//~ ang[i].fst=(ang[i].fst+180)%360;
		//~ }
		//~ if(ang[i].snd <=90 || ang[i].snd >180){
			//~ ang[i].snd=(ang[i].snd+180)%360;
		//~ }
	}
	
	forn(i,n){
		forn(j,n){
			if(j!=i){
				dd v1 = mp(cos(ang[i].fst),sin(ang[i].fst));
				dd v2 = mp(cos(ang[i].snd),sin(ang[i].snd));
				dd v3 = mp(point[j].fst-point[i].fst, point[j].snd-point[i].snd);
				cout<<"v1 "<< v1.fst<<" "<<v1.snd<<endl;
				cout<<"v2 "<< v2.fst<<" "<<v2.snd<<endl;
				cout<<"v3 "<< v3.fst<<" "<<v3.snd<<endl;
				double v13 = v1.fst*v3.fst + v1.snd*v3.snd;
				double v23 = v2.fst*v3.fst + v2.snd*v3.snd;
				double ix = v1.fst, iy=v1.snd, jx = v3.fst, jy = v3.snd;
				double modv13 = sqrt((ix*ix)+(iy*iy))*sqrt((jx*jx)+(jy*jy));
				ix = v2.fst, iy=v2.snd;
				double modv23 = sqrt((ix*ix)+(iy*iy))*sqrt((jx*jx)+(jy*jy));
				double ans = acos(v13/modv13)*(360/(2*M_PI))+acos(v23/modv23);
				cout<<acos(v13/modv13)<<" "<<acos(v23/modv23)<<endl;
				cout << ans << " " << ang[i].fst - ang[i].snd << '\n';
			}
		}
	}
	
	//~ forn(i,n){
		//~ forn(j,n){
			//~ if(j!=i){
				//~ double ans = tan(ang[i].fst)*point[j].fst-tan(ang[i].fst)*point[i].fst+point[i].snd-point[j].snd;
				//~ double ans2 = tan(ang[i].snd)*point[j].fst-tan(ang[i].snd)*point[i].fst+point[i].snd-point[j].snd;
				//~ cout << i+1 << " " << j+1 << " rta " << ans << " " << ans2 << '\n';
				//~ if(ans <= 0 && ans2 >=0 ) g[j].pb(i);
			//~ }
		//~ }
	//~ }
	vector<int> degree(n,0);
	forn(i,n) degree[i] = sz(g[i]);
	queue<int> revisar;
	vector<int> ans;
	forn(i,n)if(degree[i] == 0) revisar.push(i);
	forall(it, ans) cout << *it << " ";
	
	while(!revisar.empty()){
		int aux = revisar.front();
		ans.pb(aux);
		revisar.pop();
		forall(it, g[aux]){
			degree[*it]--;
			if(degree[*it] == 0) revisar.push(*it);
		}
	}
	if(sz(ans) == n){
		forall(it, ans) cout << *it+1 << " ";
		cout << '\n';
	}
	else cout << "-1\n";
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

