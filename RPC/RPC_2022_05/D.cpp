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
typedef long double T;
const T pi = acos(-1.0);

T volume(T h, T r){
	return (pi*r*r*h)/T(3);
}


int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	T r, s, h, m, d;
	cin >> r >> s >> h >> m >> d;
	
	T ht = (s*h)/(s-r);
	T hb = ht-h;
	T ha = hb + d;
	
	T ra = r + ((s-r)/h)*d;
	
	T vc = volume(ht,s) - volume(ha,ra);
	T vr = volume(ha,ra) - volume(hb,r);
	T dv = vc / m;
	
	cout << fixed << setprecision(9) << vr / dv << "\n";
	
	return 0;
}




