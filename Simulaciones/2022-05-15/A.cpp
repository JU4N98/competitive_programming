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

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int dist(int x1, int y1, int x2, int y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int n, a, b; 
	cin >> n >> a >> b; a--, b--;
	
	int r[4] = {0, 0, n-1, n-1};
	int c[4] = {0, n-1, 0, n-1};
	int mini = 0;
	forn(i,4){
		if(dist(r[i],c[i],a,b)<dist(r[mini],c[mini],a,b)) mini = i;
	}
	
	char m1='U', m2='U';
	int x1 = 0, y1 = 0; 
	switch(mini){
		case 0:
			x1 = 0, y1 = 0;
			m1 = 'U', m2 = 'L';
		break;
		case 1:
			x1 = 0, y1 = n-1;
			m1 = 'U', m2 = 'R';
		break;
		case 2:
			x1 = n-1, y1 = 0;
			m1 = 'D', m2 = 'L';
		break;
		case 3:
			x1 = n-1, y1 = n-1;
			m1 = 'D', m2 = 'R';
		break;
	}
	
	forn(i,n-1) cout << m1;
	forn(i,n-1) cout << m2;
	
	while(x1<a){
		cout << 'D';
		x1++;
	}
	while(x1>a){
		cout << 'U';
		x1--;
	}
	while(y1<b){
		cout << 'R';
		y1++;
	}
	while(y1>b){
		cout << 'L';
		y1--;
	}
	cout << '\n';
	
	
	return 0;
}




