/*

1.el numero de nuevos estudiantes es igual a la cantidad de indices que no aparecen en Pi

2.sabiendo el numero de estudiantes nuevos, sabemos la cantidad de iteraciones que ocurrieron (K)

3.el estudiante en la posicion i estara en la posicion TOi despues de K iteraciones, luego 
B[TOi] = A[i], si es que TOi no fue utilizado todavia

4.asignar los valores no utilizados de 1 a N a de menor a mayor en las posiciones vacias

*/

#include<bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define sz(v) v.size()
using namespace std;

vector<int> binary_lifting(vector<int> & p, int k){
	int n = sz(p);
	vector<int> to(n); 
	vector<vector<int>> dp(31,vector<int>(n));
	
	forn(i,n) to[i]=i;
	forn(i,n) dp[0][i] = p[i]-1;
	
	forr(i,1,31)
		forn(j,n)
			dp[i][j] = dp[i-1][dp[i-1][j]];
		
	forn(i,n){
		forn(j,31){
			if(k&(1<<j)) to[i]=dp[j][to[i]];
		}
	}

	return to;
}

int main()
{	
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;

	vector<int> p(n), a(n);
	set<int> dif;

	forn(i,n) cin >> p[i];
	forn(i,n) cin >> a[i];
	
	int nw=0,maxi=0,k=0;
	forn(i,n){
		dif.insert(p[i]);
		maxi = max(a[i],maxi);
	}
	nw = n-sz(dif);
	k = (maxi-n)/nw;
	
	vector<int> to = binary_lifting(p,k);

	vector<int> ans(n);
	dif.clear(); forn(i,n) dif.insert(i+1);
	forn(i,n){
		if(dif.find(a[to[i]]) == dif.end()) continue;
		ans[i] = a[to[i]];
		dif.erase(a[to[i]]);
	}
	forn(i,n){
		if(ans[i] != 0) continue;
		ans[i] = *(dif.lower_bound(a[to[i]]));
		dif.erase(dif.lower_bound(a[to[i]]));	
	}

	forn(i,n) cout << ans[i] << " ";
	cout << "\n";

	return 0;
}
