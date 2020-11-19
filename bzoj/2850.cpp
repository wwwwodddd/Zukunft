#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct P
{
	int x,y,z;
	void scan()
	{
		scanf("%d%d%d",&x,&y,&z);
	}
}ps[50020];
int n,q,k,p,type;
long long a,b,c,ans;
struct N
{
	int mx,my,nx,ny,o;
	long long sm;
	P k;
}t[200020];
bool cmpx(const P&a,const P&b)
{
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
bool cmpy(const P&a,const P&b)
{
	return a.y<b.y||a.y==b.y&&a.x<b.x;
}
void mt(int l,int r,int d,int o)
{
	if(l+1==r)
	{
		t[d].mx=t[d].nx=ps[l].x;
		t[d].my=t[d].ny=ps[l].y;
		t[d].sm=ps[l].z;
		t[d].k=ps[l];
		t[d].o=2;
			return;
	}
	sort(ps+l,ps+r,o?cmpy:cmpx);
	t[d].o=o;
	t[d].k=ps[l+r>>1];
	mt(l,l+r>>1,d*2+1,o^1);
	mt(l+r>>1,r,d*2+2,o^1);
	t[d].mx=max(t[d*2+1].mx,t[d*2+2].mx);
	t[d].nx=min(t[d*2+1].nx,t[d*2+2].nx);
	t[d].my=max(t[d*2+1].my,t[d*2+2].my);
	t[d].ny=min(t[d*2+1].ny,t[d*2+2].ny);
	t[d].sm=t[d*2+1].sm+t[d*2+2].sm;
	return;
}
inline long long cal(int x,int y)
{
	return x*a+y*b;
}
inline long long calm(const N&a)
{
	if(type==3)
		return cal(a.nx,a.ny);
	else if(type==2)
		return cal(a.nx,a.my);
	else if(type==1)
		return cal(a.mx,a.ny);
	else if(type==0)
		return cal(a.mx,a.my);
}
inline long long caln(const N&a)
{
	if(type==0)
		return cal(a.nx,a.ny);
	else if(type==1)
		return cal(a.nx,a.my);
	else if(type==2)
		return cal(a.mx,a.ny);
	else if(type==3)
		return cal(a.mx,a.my);
}
void qy(int d)
{
	long long md=calm(t[d]);
	long long nd=caln(t[d]);
	if(nd>=c)
		return;
	if(md<c)
	{
		ans+=t[d].sm;
		return;
	}
	qy(d*2+1);
	qy(d*2+2);
	return;
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
		ps[i].scan();
	mt(0,n,0,0);
	for(int i=0;i<q;i++)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		type=0;
		if(a<0)
			type|=2;
		if(b<0)
			type|=1;
		ans=0;
		qy(0);
		printf("%lld\n",ans);
	}
	return 0;
}
