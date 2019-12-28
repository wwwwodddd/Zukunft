//DNF
#include<stdio.h>
#include<iostream>
using namespace std;
int i,m,x,y,u;
int a[200020][3],tot;
int q[200020],b,f;
int d[5020];
int p[5020];
int v[5020];
int h[5020];
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
int E(int x)
{
	return max(min(x,m),0);
}
int main()
{
	scanf("%d",&m);
	while(scanf("%d %d",&x,&y),x+y)
	{
		x=E(x);
		y=E(y);
		if(x-y)
			add(x,y,1);
	}
	for(i=0;i<m;i++)
		add(i+1,i,0);
	memset(d,0x3f,sizeof(d));
	d[0]=0;
	q[f++]=0;
	while(b<f)
	{
		u=q[b++];
		v[u]=0;
		for(i=h[u];i;i=a[i][0])
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
	if(d[m]>0xffff)
		puts("No solution");
	else
	{
		printf("%d",d[m]);
		x=m;
		while(x!=0)
		{
			if(p[x]<x)
				printf("%d %d\n",p[x],x);
		}
	}
	return 0;
}