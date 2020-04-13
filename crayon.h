#ifndef CRAYON_H
#define CRAYON_H 
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define forout(n) for(ci=1;ci<=n;ci++)
using namespace std;
int cprime[1000000];
int ci;
namespace crand{
	bool isInit;
	int MTindex;
	ll MT[624];
	void csrand(int seed) {
		MTindex=0;
		isInit=1;
		MT[0]=seed;
		for(int i=1;i<624;i++) {
			int t=1812433253*(MT[i-1]^(MT[i-1]>>30))+i;
			MT[i]=t&0xffffffff;
		}
	}
	inline void generate() {
		for(int i=0;i<624;i++) {
			long long y=(MT[i]&0x80000000)+(MT[(i+1)%624]&0x7fffffff);
			MT[i]=MT[(i+397)%624]^(y>>1);
			if(y%2==1) MT[i]^=2147483647;
		}
	}
	inline int cyrand() {
		if(!isInit) csrand((int)time(NULL));
		if(MTindex==0) generate();
		int y=MT[MTindex];
		y=y^(y>>11);
		y=y^((y<<7)&1636928640);
		y=y^((y<<15)&1022730752);
		y=y^(y>>18);
		MTindex=(MTindex+1)%624;
		return y;
	}
	inline ll cyrand_ll() {
		return ((ll)(cyrand())<<31)+cyrand();
	}
	inline int cyrand(int a,int b) {
		if(a>b) a=b;
		if(a==b) return a;
		else return cyrand()%(b-a+1)+a;
	}
	inline ll cyrand_ll(ll a,ll b) {
		if(a>b) a=b;
		if(a==b) return a;
		else return cyrand_ll()%(b-a+1)+a;
	}
	
}
namespace cmath{
	inline double cpi(){
		return 3.141592653589793238462643383279502884197169399;
	}
	inline ld cdistance(ld a1,ld a2,ld b1,ld b2){
		return sqrt((a1-b1)*(a1-b1)+(a2-b2)*(a2-b2));
	}
	template<typename T>
	inline T cabs(T a){
		return a>0?a:-a;
	}
	inline int cmin(int a,int b){
		return a<b?a:b;
	}
	inline int cmax(int a,int b){
		return a>b?a:b;
	}
	inline int cgcd(int a,int b){
		return a==0?b:cgcd(b%a,a);
	}
	bool isprime(int a){
		if(a<2)	return false;
		for(int i=2;i<=sqrt(a);++i){
			if(a%i==0)	return false;
		}
		return true;
	}
	int cmakeprime(int a,int b){
		int prcnt=0;
		for(int i=a;i<=b;i++){
			if(isprime(i)){
				cprime[prcnt]=i;
				prcnt++;
			}
		}
	}
	inline int crprimenum(int beg,int end){
		return cprime[crand::cyrand(beg,end)];
	}
}
namespace inout{
	inline void inint(int a){
		string c,ccci,tnmp;
		stringstream ss,cci;
		ss<<a;
		ss>>c;
		cci<<ci;
		cci>>ccci;
		string name="data"+ccci+".in";
		freopen(name.c_str(),"w",stdout);
		freopen(name.c_str(),"r",stdin);
		cin>>tnmp;
		c=tnmp+c;
		cout<<c;
	}
	inline void instring(string a){
		string ccci,tnmp;
		stringstream cci;
		cci<<ci;
		cci>>ccci;
		string name="data"+ccci+".in";
		freopen(name.c_str(),"w",stdout);
		freopen(name.c_str(),"r",stdin);
		cin>>tnmp;
		a=tnmp+a;
		cout<<a;
	}
}
namespace ca{
	using namespace crand;
	using namespace cmath;
	using namespace inout;
}
#endif
