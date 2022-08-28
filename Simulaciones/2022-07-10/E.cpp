#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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
typedef double T;
const T EPS = 0.0000000001;
const T INF = 100000.;
T dp[201][512][201];
T add[200][512];

struct pt {  
	T x,y;
	pt(T x, T y):x(x),y(y){}
	pt(){}
	T norm2(){return *this**this;}
	T norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(T t){return pt(x*t,y*t);}
	pt operator/(T t){return pt(x/t,y/t);}
	T operator*(pt p){return x*p.x+y*p.y;}
	T angle(pt p){ 
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	T operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p)const{ 
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ 
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(T a){return rot(pt(sin(a),cos(a)));}
};

int sgn2(T x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;}
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ 
		if(*this/l)return pt(INF,INF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	T angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	T dist(pt r){return (r-proj(r)).norm();}
	ln rot(auto a){return ln(p,p+pq.rot(a));} 
};

int sgn(T x){return x<-EPS?-1:x>EPS;}
struct pol {
	int n;vector<pt> p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=p.size();}
	T area(){
		T r=0.;
		forr(i,0,n)r+=p[i]%p[(i+1)%n];
		return abs(r)/2; // negative if CW, positive if CCW
	}
	pol cut(ln l){   // cut CONVEX polygon by line l
		vector<pt> q;  // returns part at left of l.pq
		forr(i,0,n){
			int d0=sgn(l.pq%(p[i]-l.p)),d1=sgn(l.pq%(p[(i+1)%n]-l.p));
			if(d0>=0)q.pb(p[i]);
			ln m(p[i],p[(i+1)%n]);
			if(d0*d1<0&&!(l/m))q.pb(l^m);
		}
		return pol(q);
	}
};

T polyArea(vector<int> &height, vector<pair<ii,ii>> &rect, pair<ii,ii> interest){
	int curx = interest.fst.fst, fin = interest.fst.snd;
	
	T sum = 0.;
	// iterates over all 1-width-x ranges
	while(curx != fin){
		
		if(curx<0 || (curx >= sz(height)-1)){
			curx++;
			continue;
		}
		
		// chooses rectangles that contains current 1-width-x range
		vector<ii> range;
		range.reserve(10);
		forn(i,sz(rect))
			if(curx >= rect[i].fst.fst && curx < rect[i].fst.snd)
				range.pb(rect[i].snd);
		
		
		ii newRange = interest.snd;
		forn(i,sz(range)){
			if(range[i].fst < interest.snd.fst){
				newRange = {max(range[i].snd,newRange.fst),newRange.snd};
			}else{
				assert(range[i].snd>=interest.snd.snd);
				newRange = {newRange.fst,min(range[i].fst,newRange.snd)};
			}
		}
		
		if(newRange.fst >= newRange.snd){
			curx++;
			continue;
		}
		
		// cuts the current polygon with the rectangle
		vector<pt> p(4);
		p[0] = pt(curx,0.); 
		p[1] = pt(curx+1,0.); 
		p[2] = pt(curx+1,height[curx+1]); 
		p[3] = pt(curx,height[curx]);
		pol hill = pol(p);
		sum += hill.cut(ln(pt(curx,newRange.fst),pt(curx+1,newRange.fst)))
			.cut(ln(pt(curx+1,newRange.snd),pt(curx,newRange.snd)))
			.area();
		
		curx++;
	}
	
	return sum;
}

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, w ,h;
	cin >> n >> w >> h;
	vector<int> height(n+2);
	forn(i,n) cin >> height[i+1];
	
	vector<pair<ii,ii>> rect(n);
	forn(i,n)
		rect[i] = {{i+1-w,i+1+w},{height[i+1]-h,height[i+1]+h}};
	
	forn(pos,n){
		forn(uso,512){
			vector<pair<ii,ii>> auxRect;
			
			forn(i,9)
				if(uso&(1<<i) && pos-(i+1)>-1) 
					auxRect.pb(rect[pos-(i+1)]);
			
			add[pos][uso] = polyArea(height,auxRect,rect[pos]);
		}
	}
	
	vector<T> ans(n+2);
	forn(pos,n){
		forn(uso,512){
			forn(count,n){
				int shift = (uso*2)%512;
				
				dp[pos+1][shift][count] = max(dp[pos+1][shift][count], dp[pos][uso][count]);
				ans[count] = max(ans[count], dp[pos+1][shift][count]);
				
				dp[pos+1][shift+1][count+1] = max(dp[pos+1][shift+1][count+1],dp[pos][uso][count] + add[pos][uso]);
				ans[count+1] = max(ans[count+1], dp[pos+1][shift+1][count+1]);
			}
		}
	}
	
	forr(i,1,n+1) cout << fixed << setprecision(8) << ans[i] << "\n";
	
	return 0;
}
