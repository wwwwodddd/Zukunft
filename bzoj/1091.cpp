#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,l;
double eps=1e-8,ans=1e30;
struct P
{
	double x,y;
	void scan()
	{
		scanf("%lf %lf",&x,&y);	
	}
}p[10],s[10],f[10],o;
int pc,sc,fc;
pair<P,P>a[10];
bool operator<(const P&a,const P&b)
{
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
inline double dis(const P&a,const P&b)
{
	return hypot(a.x-b.x,a.y-b.y);
}
int sgn(double x)
{
	return x<-eps?-1:x>eps;	
}
double xm(const P&a,const P&b,const P&c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
P cp(const P&as,const P&ae,const P&bs,const P&be)
{
	P re;
	double u=xm(as,ae,bs);
	double v=xm(ae,as,be);
	re.x=(bs.x*v+be.x*u)/(u+v);
	re.y=(bs.y*v+be.y*u)/(u+v);
	return re;
}
void ins(const P&a,const P&b)
{
	sc=0;
	memset(s,0,sizeof s);
	for(int i=0;i<pc;i++)
	{
		if(sgn(xm(a,b,p[i]))>=0)
			s[sc++]=p[i];
		if(sgn(xm(a,b,p[i]))==0)
			f[fc++]=s[sc-1];
		if(sgn(xm(a,b,p[i])*xm(a,b,p[i+1]))<0)
		{
			s[sc++]=cp(a,b,p[i],p[i+1]);
			f[fc++]=s[sc-1];
		}
	}
	pc=sc;
	if(sc==0)
		return;
	memcpy(p,s,sizeof s);
	p[pc]=p[0];
	return;
}
double cal()
{
	double re=0;
	memset(p,0,sizeof p);
	p[0]=(P){0,0};
	p[1]=(P){n,0};
	p[2]=(P){n,m};
	p[3]=(P){0,m};
	p[pc=4]=p[0];
	for(int i=0;i<l;i++)
	{
		fc=0;
		ins(a[i].X,a[i].Y);
		re+=dis(f[0],f[1]);
		if(fc==1)
			cerr << "error" << endl;
	}
	return re;
}
double S(P P[],int n)
{
	double re=0;
	for(int i=0;i<n;i++)
		re+=xm(o,p[i],p[i+1]);
	return fabs(re/2);
}
int main()
{
	scanf("%d %d %d",&n,&m,&l);
	for(int i=0;i<l;i++)
		p[i].scan();
	p[l]=p[0];
	if(S(p,l)<0)
		reverse(p,p+l);
	for(int i=0;i<l;i++)
		a[i]=make_pair(p[i+1],p[i]);
	sort(a,a+l);
	do
		ans=min(ans,cal());	
	while(next_permutation(a,a+l));
	printf("Minimum total length = %.3lf\n",ans);
	return 0;
}
