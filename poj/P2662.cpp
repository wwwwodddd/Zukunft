#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
int a[500020][3],tot;
int q[100020],b,f;
int h[1020];
int d[1020];
int v[1020];
int g[1020];
int n,m;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
void spfa()
{
	int i,j,u;
	memset(v,0,sizeof(v));
	memset(d,0x3f,sizeof(d));
	d[2]=0;
	b=f=0;
	q[f++]=2;
	while(b<f)
	{
		u=q[b++];
		v[u]=0;
		for(i=h[u];i;i=a[i][0])
		{
			if(d[a[i][1]]>d[u]+a[i][2])
			{
				d[a[i][1]]=d[u]+a[i][2];
				if(!v[a[i][1]])
				{
					q[f++]=a[i][1];
					v[a[i][1]]=1;
				}
			}
		}
	}
}
int G(int x)
{
	int i;
	if(v[x])
		return g[x];
	v[x]=1;
	for(i=h[x];i;i=a[i][0])
		if(d[x]>d[a[i][1]])
			g[x]+=G(a[i][1]);
	return g[x];
}
int main()
{
	int x,y,z;
	while(scanf("%d",&n),n)
	{
		scanf("%d",&m);
		memset(g,0,sizeof(g));
		memset(h,0,sizeof(h));
		tot=0;
		while(m--)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		spfa();
		memset(v,0,sizeof(v));
		v[2]=1;
		g[2]=1;
		printf("%d\n",G(1));
	}
	return 0;
}