#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(a,b,c) for(int a=b; a<c;a++)
#define forn(i,n) forr(i,0,n)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define snd second
#define fst first
#define pb push_back
#define ll long long
//#define ANARAP

int main(){
	#ifdef ANARAP
		freopen("input.in","r",stdin);
	#endif
	
	ll t;
	cin>>t;
	forn(T,t){
		string s, aux="";
		cin>>s;
		stack<ll> cora, corc, preg;
		forn(i,s.size()){
			if(s[i]=='('){
				cora.push(i);
			}else if(s[i]==')'){
				if(cora.empty()){
					corc.push(i);
				}else{
					cora.pop();
				}
			}else {
				preg.push(i);
			}
		}
		vector<ll> cop;
		while(!cora.empty()){ cop.pb(cora.top()); cora.pop();}
		sort(cop.begin(),cop.end());
		for(int i=cop.size()-1;i>-1;i--) cora.push(cop[i]);
		cop.clear();
		while(!corc.empty()){ cop.pb(corc.top()); corc.pop();}
		sort(cop.begin(),cop.end());
		for(int i=cop.size()-1;i>-1;i--) corc.push(cop[i]);
		cop.clear();
		while(!preg.empty()){ cop.pb(preg.top()); preg.pop();}
		sort(cop.begin(),cop.end());
		for(int i=cop.size()-1;i>-1;i--) preg.push(cop[i]);
		cop.clear();
		vector<ll> arr(3);
		while(!cora.empty() || !corc.empty() || !preg.empty()){
			if(!cora.empty()) arr[0]=cora.top(); else arr[0]=LLONG_MAX;
			if(!corc.empty()) arr[1]=corc.top(); else arr[1]=LLONG_MAX;
			if(!preg.empty()) arr[2]=preg.top(); else arr[2]=LLONG_MAX;
			sort(arr.begin(),arr.end());
			if(!cora.empty() && arr[0]==cora.top()){
				aux+="(";
				cora.pop();
			}else if(!corc.empty() && arr[0]==corc.top()){
				aux+=")";
				corc.pop();
			}else if(!preg.empty() && arr[0]==preg.top()){
				aux+="?";
				preg.pop();
			}
		}
		bool sol=true;
		ll cant=0;
		forn(i,aux.size()){
			if(aux[i]=='?'){
				cant++;
				aux[i]='X';
			}else if(aux[i]=='('){
				break;
			}else if(aux[i]==')'){
				cant--;
			}
			if(cant<0) sol=false;
		}
		
		ll cant2=0;
		for(int i=aux.size()-1;i>-1;i--){
			if(aux[i]=='?'){
				cant2++;
			}else if(aux[i]=='('){
				cant2--;
			}else if(aux[i]==')'){
				break;
			}
			if(cant2<0) sol=false;
		}
		if(sol){
			if((cant+cant2)%2==0) cout<<"YES\n"; else cout<<"NO\n";
		}else{
			cout<<"NO\n";
		}
		
	}
	
	return 0;
}
