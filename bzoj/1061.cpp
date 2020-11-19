#include<stdio.h>
#include<string.h>
#include<iostream>
#define inf 0x3f3f3f3f
using namespace std;
int e[100020][4];
int h[1020];
int d[1020];
int v[1020];
int p[1020];
int f[1020];
int q[400020],bb,ff;
int n,m,s,t;
int csc,ans,tot;
void add(int x,int y,int z,int w)
{
	tot++;
	e[tot][0]=h[x];
	e[tot][1]=y;
	e[tot][2]=z;
	e[tot][3]=w;
	h[x]=tot;

	tot++;
	e[tot][0]=h[y];
	e[tot][1]=x;
	e[tot][2]=0;
	e[tot][3]=-w;
	h[y]=tot;
}
int spfa()
{
	int i,u;
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	bb=ff=0;
	q[ff++]=s;
	d[s]=0;
	v[s]=1;
	while(bb<ff)
	{
		u=q[bb++];
		v[u]=0;
		for(i=h[u];i;i=e[i][0])
			if(e[i][2]&&d[e[i][1]]>d[u]+e[i][3])
			{
				d[e[i][1]]=d[u]+e[i][3];
				p[e[i][1]]=i;
				if(!v[e[i][1]])
				{
					q[ff++]=e[i][1];
					v[e[i][1]]=1;
				}
			}
	}
	return d[t]!=inf;
}
void ek()
{
	int i,a=inf;
	for(i=t;i!=s;i=e[p[i]^1][1])
		a=min(a,e[p[i]][2]);
	for(i=t;i!=s;i=e[p[i]^1][1])
		e[p[i]][2]-=a,e[p[i]^1][2]+=a;
	ans+=d[t]*a;
}
int main()
{
	int i,j,k,x,y,z;
	tot=1;
	scanf("%d%d",&n,&m);
	s=0;
	t=n+2;
	for(i=1;i<=n;i++)
		scanf("%d",&f[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y+1,inf,z);
	}
	for(i=1;i<=n+1;i++)
	{
		z=f[i]-f[i-1];
		if(z>=0)
			add(s,i,z,0);
		else
			add(i,t,-z,0);
		if(i>1)
			add(i,i-1,inf,0);
	}
	while(spfa())
		ek();
	printf("%d\n",ans);
	return 0;
}