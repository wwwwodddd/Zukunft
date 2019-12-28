#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
int a[500020][3],tot;
int q[100020],b,f;
int h[10020];
int d[10020];
int v[10020];
int g[10020];
int n,m;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
void spfa(int x)
{
	int i,j,u;
	memset(v,0,sizeof(v));
	memset(d,0x3f,sizeof(d));
	d[x]=0;
	b=f=0;
	q[f++]=x;
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
int main()
{
	int x,y,z,i;
	while(scanf("%d%d%d",&x,&y,&z)+1)
	{
		add(x,y,z);
		add(y,x,z);
		n++;
	}
	n++;
	spfa(1);
	for(z=i=1;i<=n;i++)
		if(d[i]>d[z])
			z=i;
	spfa(z);
	for(i=1;i<=n;i++)
		if(d[i]>d[z])
			z=i;
	printf("%d\n",d[z]);
	return 0;
}