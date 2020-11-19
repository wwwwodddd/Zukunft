#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
double eps=1e-8;
int sgn(double x){
	return x<-eps?-1:x>eps;
}
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
}p[1020],s[1020],a[1020];
int pc,sc,n,m;
#define xm(a,b,c) ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y))
#define sgx(a,b,c) (sgn(xm(a,b,c)))
P sect(P a,P b,P c,P d){
	double u=xm(a,b,c),v=xm(b,a,d);
	return (c*v+d*u)/(u+v);
}
bool inter(P a,P b,P c,P d){
	return sgx(a,b,c)*sgx(a,b,d)<0&&sgx(c,d,a)*sgx(c,d,b)<0;
}
void cut(P a,P b)
{
	memset(s,0,sizeof s);
	sc=0;
	for(int i=0;i<pc;i++)
	{
		if(sgx(a,b,p[i])>=0)
			s[sc++]=p[i];
		if(sgx(a,b,p[i])*sgx(a,b,p[i+1])<0)
			s[sc++]=sect(a,b,p[i],p[i+1]);
	}
	memcpy(p,s,sizeof s);
	pc=sc;
	p[pc]=p[0];
	return;		
}
double S(P P[],int n)
{
	double re=0;
	for(int i=0;i<n;i++)
		re+=p[i].det(p[i+1]);
	return fabs(re/2);
}
int main()
{
	p[0]=(P){1e5,-1e5};
	p[1]=(P){1e5,1e5};
	p[2]=(P){-1e5,1e5};
	p[3]=(P){-1e5,-1e5};
	p[pc=4]=p[0];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			a[i].scan();
		for(int i=0;i<m;i++)
			cut(a[i],a[(i+1)%m]);
	}
	printf("%.3f",S(p,pc));
	return 0;
}
