#include<stdio.h>
#include<string.h>
#include<iostream>
#define inf 0x3f3f3f3f
using namespace std;
int e[200020][4];
int h[5010];
int d[5010];
int v[5010];
int p[5010];
int l[200020];
int c[200020];
int q[200020],bb,ff;
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
	memset(d,-1,sizeof(d));
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
			if(e[i][2]&&d[e[i][1]]<d[u]+e[i][3])
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
	return d[t]!=-1;
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
	int i,j,k,w;
	tot=1;
	scanf("%d%d",&n,&k);
	s=0;
	t=n*n*2+1;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&w);
			add((i-1)*n+j,(i-1)*n+j+n*n,1,w);
			add((i-1)*n+j,(i-1)*n+j+n*n,inf,0);
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(i<n)
				add((i-1)*n+j+n*n,i*n+j,inf,0);
			if(j<n)
				add((i-1)*n+j+n*n,(i-1)*n+j+1,inf,0);
		}
	add(s,1,k,0);
	add(n*n*2,t,k,0);
	while(spfa())
		ek();
	printf("%d\n",ans);
	return 0;
}