#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<assert.h>
#define fr(i,n) for(int i=0;i<n;i++)
#define fe(i,n) for(auto i=n.begin();i!=n.end();i++)
//#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
using namespace std;
const double eps=1e-8;
int times;
int sgn(double x){
	return x<-eps?-1:x>eps;
}
struct P{
	double x,y,z;
	void scan(){
		scanf("%lf%lf%lf",&x,&y,&z);
	}
	P(){
	}
	P(double x,double y,double z):
		x(x),y(y),z(z){
	}
	P operator+(P a){
		return P(x+a.x,y+a.y,z+a.z);
	}
	P operator-(P a){
		return P(x-a.x,y-a.y,z-a.z);
	}
	P operator*(double f){
		return P(x*f,y*f,z*f);
	}
	P operator/(double f){
		return P(x/f,y/f,z/f);
	}
	double dot(P a){
		return x*a.x+y*a.y+z*a.z;
	}
	P det(P a){
		return P(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
	}
	double abs(){
		return sqrt(x*x+y*y+z*z);
	}
	P nom(){
		return *this/abs();
	}
	void print(){
		printf("%.6f %.6f %.6f\n",x,y,z);
	}
};
double div(P a,P b)
{
	if(sgn(b.x))
		return a.x/b.x;
	if(sgn(b.y))
		return a.y/b.y;
	if(sgn(b.z))
		return a.z/b.z;
	assert(0);
}
namespace G2D{
	struct P{
		double x,y;
		void scan(){
			scanf("%lf%lf",&x,&y);
		}
		P(){
		}
		P(double x,double y):
			x(x),y(y){
		}
		P operator+(const P &a)const{
			return P(x+a.x,y+a.y);
		}
		P operator-(const P &a)const{
			return P(x-a.x,y-a.y);
		}
		P operator*(double f)const{
			return P(x*f,y*f);
		}
		P operator/(double f)const{
			return P(x/f,y/f);
		}
		double dot(const P &a)const{
			return x*a.x+y*a.y;
		}
		double det(const P &a)const{
			return x*a.y-y*a.x;
		}
		double abs()const{
			return hypot(x,y);
		}
		P nom()const{
			return *this/abs();
		}
		double agl()const{
			return atan2(y,x);
		}
		P rot90()const{
//counter-clock wise
			return P(-y,x);
		}
		double dis(const P &a)const{
			return hypot(x-a.x,y-a.y);
		}
		bool operator<(const P &a)const{
			if(sgn(x-a.x))
				return x<a.x;
			return y<a.y;
		}
		void print()const{
			printf("%.6f %.6f\n",x,y);
		}
	};
#define xm(a,b,c) ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y))
#define sgx(a,b,c) (sgn(xm(a,b,c)))
	P isSS(P a,P b,P c,P d){
		double u=xm(a,b,c),v=xm(b,a,d);
		return (c*v+d*u)/(u+v);
	}
	bool bisSS(P a,P b,P c,P d){
		return sgx(a,b,c)*sgx(a,b,d)<0&&sgx(c,d,a)*sgx(c,d,b)<0;
	}
	typedef vector<P> plg;
	plg Ccut(const plg &ps,P a,P b){
		plg re;
		int n=ps.size();
		fr(i,n){
			P c=ps[i],d=ps[(i+1)%n];
			int d1=sgx(a,b,c),d2=sgx(a,b,d);
			if(d1>=0)
				re.push_back(c);
			if(d1*d2<0)
				re.push_back(isSS(a,b,c,d));
		}
		return re;
	}
	double S(const plg &ps){
		int n=ps.size();
		double re=0;
		fr(i,n){
			re+=ps[i].det(ps[(i+1)%n]);
		}
		return re*0.5;
	}
	void nom(plg&ps){
		if(S(ps)<0)
			reverse(ps.begin(),ps.end());
	}
	plg isCC(plg ps,plg qs){
		int n=qs.size();
		fr(i,n){
			ps=Ccut(ps,qs[i],qs[(i+1)%n]);
			if(ps.size()<=1)
				return plg();
		}
		return ps;
	}
	struct seg{
		double l,r;
		seg(){
		}
		seg(double l,double r):
			l(l),r(r){
		}
		bool operator<(const seg&a)const{
			if(sgn(l-a.l))
				return l<a.l;
			return r>a.r;
		}
		bool good(){
			return r-l>eps;
		}
	};
	seg Gcut(const plg &ps,double x){
		int n=ps.size();
		double ym=-1e100,yn=1e100;
		fr(i,n)
		{
			P c=ps[i],d=ps[(i+1)%n];
			int d1=sgn(c.x-x),d2=sgn(d.x-x);
			if(d1==0){
				ym=max(ym,c.y);
				yn=min(yn,c.y);
			}
			if(d1*d2<0){
				P a(x,-1e4),b(x,1e4);
				P is=isSS(a,b,c,d);
				ym=max(ym,is.y);
				yn=min(yn,is.y);
			}
		}
		return seg(yn,ym);
	}
	double Cutlen(const vector<plg>&pss,double x)
	{
		seg s[10020];
		int ss=0;
		fe(it,pss){
			seg cur=Gcut(*it,x);
			if(cur.good()){
				s[ss++]=cur;
			}
		}
		sort(s,s+ss);
		double cl,cr,re=0;
		cl=cr=-1e100;
		fr(i,ss)
		{
			seg &cur=s[i];
			if(cr<cur.l){
				re+=cr-cl;
				cl=cur.l;
				cr=cur.r;
			}else{
				cr=max(cr,cur.r);
			}
		}
		re+=cr-cl;
		return re;
	}
	plg isPCC(plg ps,plg qs){
		plg is;
		int n=ps.size();
		int m=qs.size();
		fr(i,n)
			fr(j,m){
				P a=ps[i],b=ps[(i+1)%n];
				P c=qs[j],d=qs[(j+1)%m];
				if(bisSS(a,b,c,d))
					is.push_back(isSS(a,b,c,d));
				}
		return is;
	}
	double sumS(const vector<plg>&pss){
		double xs[100020];
		int xc=0;
		fe(it,pss)
			fe(ti,(*it))
				xs[xc++]=ti->x;
		fr(i,pss.size())
			fr(j,i){
				plg is=isPCC(pss[i],pss[j]);
				fe(it,is)
					xs[xc++]=it->x;
			}
		sort(xs,xs+xc);
		double re=0;
		fr(i,xc-1){
			double l=xs[i],r=xs[i+1];
			double m=(l+r)/2;
			if(r-l<eps)
				continue;
			re+=(r-l)*Cutlen(pss,m);
		}
		return re;
	}
	plg CH(plg ps){
		int n=ps.size();
		sort(ps.begin(),ps.end());
		P qs[10020];
		int k=0;
		fr(i,n){
			while(k>1&&sgx(qs[k-2],qs[k-1],ps[i])<=0)
				k--;
			qs[k++]=ps[i];
		}
		for(int t=k,i=n-2;i>=0;i--){
			while(k>t&&sgx(qs[k-2],qs[k-1],ps[i])<=0)
				k--;
			qs[k++]=ps[i];
		}
		if(k<=2)
			return plg();
		return plg(qs,qs+k-1);
	}
};
typedef G2D::P P2D;
struct Pn{
	P nom;
	P ap;
	P d1,d2;
	void set(P a,P b,P c){
		nom=(b-a).det(c-a).nom();
		ap=a;
		d1=(b-a).nom();
		d2=nom.det(d1).nom();
		assert(sgn(d1.abs()-1)==0);
		assert(sgn(d2.abs()-1)==0);
		assert(sgn(d1.dot(d2))==0);
	}
	double dis(P a){
		return (ap-a).dot(nom);
	}
	bool inPn(P a){
		return sgn(a.dot(nom))==0;
	}
	P get(P a,P v){
//v.abs()==1
//sgn(v.dot(re-a))==0
		double d=dis(a);
		assert(sgn(dis(a+nom*d))==0);
		double cosa=nom.dot(v);
		double dv=d/cosa;
		return a+v*dv;
	}
	P2D trs2D(P a){
		assert(sgn((a-ap).dot(nom))==0);
		P v=a-ap;
		return P2D(v.dot(d1),v.dot(d2));
	}
	P trs3D(P2D a){
		return ap+d1*a.x+d2*a.y;
	}
	P gR(P v){
		P u=v-nom*2*(v.dot(nom));
//		printf("====>");
//		u.print();
		return u;
	}
	bool bisPP(P a,P b){
		if(sgn(dis(a))*sgn(dis(b))<0)
			return 1;
		return 0;
	}
	P isPP(P a,P b){
		P v=(b-a).nom();
		return get(a,v);
	}
};
typedef G2D::plg plg2D;
int np,nr,nf;
/*void print(vector<P> a)
{
	printf("%d :\n",a.size());
	fe(i,a)
		i->print();
}*/
P p[100020];
struct F{
	vector<P>ps;
	Pn pn;
	plg2D sf;
	vector<plg2D>plgs;
	void scan(){
		int n;
		scanf("%d",&n);
		fr(i,n){
			int x;
			scanf("%d",&x);
			x--;
			ps.push_back(p[x]);
		}
		pn.set(ps[0],ps[1],ps[2]);
		fr(i,n)
			sf.push_back(pn.trs2D(ps[i]));
		sf=G2D::CH(sf);
		G2D::nom(sf);
//		printf("%d :\n",sf.size());
//		fe(i,sf)
//			i->print();
	}
	int sgnL(P l,P lv){
		P at=pn.get(l,lv);
		assert(sgn(pn.dis(at))==0);
		P gn=at-l;
		return sgn(div(gn,lv));
	}
	plg2D git(vector<P>l,P lv){
//		printf("lightV:");
//		lv.print();
//		print(l);
		times++;
		if(pn.inPn(lv))
			return plg2D();
		int n=l.size();
		plg2D re;
//		if(times==9)
//			puts("stop");
		fr(i,n){
			P a=l[i],b=l[(i+1)%n];
			int c1=sgnL(a,lv),c2=sgnL(b,lv);
			if(c1>=0)
				re.push_back(pn.trs2D(pn.get(a,lv)));
			if(c1*c2<0)
				re.push_back(pn.trs2D(pn.isPP(a,b)));
		}
		re=G2D::CH(re);
		G2D::nom(re);
		re=G2D::isCC(re,sf);
//		printf("--------%d--------\n",times);
//		printf("%d :\n",re.size());
//		fe(i,re)
//			i->print();
//		system("pause");
		return re;
	}
	void add(vector<P>l,P lv){
//		printf("lightV:");
//		lv.print();
		plg2D re=git(l,lv);
//		fe(j,re)
//			j->print();
		if(re.empty())
			return;
		plgs.push_back(re);
	}
	void ref(vector<P> l,P lv,vector<P> &nl,P &nlv){
		plg2D re=git(l,lv);
		nl.clear();
		if(re.empty()||pn.inPn(lv))
			return;
		vector<P>at;
		fe(it,re)
			at.push_back(pn.trs3D(*it));
		nl=at;
		nlv=pn.gR(lv).nom();
	}
	double work(vector<P> l,P lv){
		if(pn.inPn(lv))
			return 0;
		plg2D re=git(l,lv);
		return G2D::S(re);
	}
	double calS(){
		return G2D::S(sf);
	}
	double calA(){
		return G2D::sumS(plgs);
	}
};
F f[10020];
vector<P>l;
P lv;
double work(){
	double re=0;
	fr(i,nf){
		double u=f[i].work(l,lv);
		re+=u;
	}
	printf("%.6f\n",re);
	return re;
}

void dfs(vector<P> l,P lv,int nr,int y){
//	print(l);
//	printf("%d %d\n",nr,y);
//	system("pause");
	fr(i,nf){
		if(i==y)
			continue;
		f[i].add(l,lv);
	}
	if(nr==1)
		return;
	fr(i,nf){
		if(i==y)
			continue;
		vector<P>nl;
		P nlv;
//		puts("callref");
		f[i].ref(l,lv,nl,nlv);
//		print(l);
//		print(nl);
//		system("pause");
//		print(nl);
		if(nl.empty())
			continue;
		dfs(nl,nlv,nr-1,i);
	}
	return;
}
int main()
{
	scanf("%d %d %d",&np,&nf,&nr);
	fr(i,np)
		p[i].scan();
	fr(i,nf)
		f[i].scan();
	fr(i,3){
		P p;
		p.scan();
		l.push_back(p);
	}
	lv.scan();
	lv=lv.nom();
	dfs(l,lv,nr,-1);
	double re=0;
	fr(i,nf){
		double u=f[i].calA();
//		cout<<u<<endl;
		re+=u;
	}
	printf("%0.2f\n",re);
	return 0;
}