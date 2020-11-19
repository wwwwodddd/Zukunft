#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
int f[100020];
int s[100020],ss;
int v[100020],vv;
int q[100020],bb,ff;
int h[100020];
int a[4000020][2],tot;
int z[100020],zz;
int n,m;
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
int F(int x)
{
	int i;
	ss=0;
	while(f[x]!=x)
	{
		s[ss++]=x;
		x=f[x];
	}
	for(i=0;i<ss;i++)
		f[s[i]]=x;
	return x;
}
void del(int x)
{
	f[x]=x+1;
}
int main()
{
	int i,j,x,y,now;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(i=1;i<=n+1;i++)
		f[i]=i;
	while(F(1)!=n+1)
	{
		bb=ff=0;
		q[ff++]=F(1);
		del(F(1));
		while(bb<ff)
		{
			vv++;
			now=q[bb++];
			for(i=h[now];i;i=a[i][0])
				v[a[i][1]]=vv;
			for(j=F(1);j!=n+1;j=F(j+1))
				if(v[j]!=vv)
					q[ff++]=j,del(j);
		}
		z[zz++]=ff;
	}
	printf("%d\n",zz);
	sort(z,z+zz);
	for(i=0;i<zz;i++)
		printf("%d ",z[i]);
	return 0;
}