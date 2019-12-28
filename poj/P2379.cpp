#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct list
{
	int u,v,r,p1[22],p2[22];
}a[1002];
struct in
{
	int c,p,t,r;
}b[1002];
int cmp1(in x, in y)
{
	return x.t<y.t;
}
int cmp2(list x,list y)
{
	if(x.u==y.u&&x.v==y.v)
		return x.r<y.r;
	else if(x.u==y.u)
		return x.v<y.v;
	return x.u>y.u;
}
int main()
{
	int m,n;
	int c,p,t,r,i;
	scanf("%d%d",&m,&n);
	memset(a,0,sizeof(a));
	for(i=1;i<=m;i++)
		a[i].r=i;
	for(i=1;i<=n;i++)
		scanf("%d%d%d%d",&b[i].c,&b[i].p,&b[i].t,&b[i].r);
	sort(b+1,b+1+n,cmp1);
	for(i=1;i<=n;i++)
	{
		c=b[i].c;
		p=b[i].p;
		t=b[i].t;
		r=b[i].r;
		if(r==0)
			a[c].p1[p]+=1200;
		if(r==1&&a[c].p2[p]==0)
		{
			a[c].u+=1;
			a[c].v+=(a[c].p1[p]+t);
			a[c].p2[p]=1;
		}
	}
	sort(a+1,a+1+m,cmp2);
	for(i=1;i<=m;i++)
		printf("%d ",a[i].r);
	return 0;
}