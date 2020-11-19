#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct E{int s,t,v;}e[10020];
int f[520];
int n,m,i,j,k,s,t;
int ax,ay,gd;
bool cmp(E a,E b)
{
	return a.v<b.v;
}
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
void U(int x,int y)
{
	f[F(x)]=F(y);
}
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main()
{
	ay=30001;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d %d %d",&e[i].s,&e[i].t,&e[i].v);
	scanf("%d %d",&s,&t);
	sort(e,e+m,cmp);
	for(i=0;i<m;i++)
	{
		for(j=1;j<=n;j++)
			f[j]=j;
		for(j=i;j<m&&e[j].v*ax<e[i].v*ay;j++)
		{
			U(e[j].s,e[j].t);
			if(F(s)==F(t))
				break;
		}
		if(j<m)
		{
			if(e[j].v*ax<ay*e[i].v)
			{
				ax=e[i].v;
				ay=e[j].v;
			}
		}
		else
			break;
	}
	if(ay<30001)
	{
		gd=gcd(ax,ay);
		ay/=gd;
		ax/=gd;
		if(ax==1)
			printf("%d",ay);
		else
			printf("%d/%d",ay,ax);
	}
	else
		puts("IMPOSSIBLE");
	return 0;
}