#include<stdio.h>
#include<string.h>
#include<iostream>
#define inf 0x3f3f3f3f
using namespace std;
int e[1000020][4];
int f[160][160];
int h[350];
int d[350];
int v[350];
int p[350];
int q[5000020],bb,ff;
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
	int i,j,k,w,x,y,z;
	tot=1;
	scanf("%d %d %d",&n,&m,&w);
	memset(f,0x3f,sizeof(f));
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		f[y][x]=f[x][y]=min(z,f[x][y]);
	}
	s=2*n+1;
	t=2*n+2;
	add(s,0,w,0); 
	for(k=0;k<n;k++)
	{
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				if(f[i][j]>f[i][k]+f[k][j])
					f[i][j]=f[i][k]+f[k][j];
		add(0,k+1,w,f[0][k+1]);
		for(i=1;i<=k;i++)
			add(i+n,k+1,w,f[i][k+1]);
	}
	for(i=1;i<=n;i++)
	{
		add(s,i+n,1,0);
		add(i,t,1,0);
	}
	while(spfa())
		ek();
	printf("%d\n",ans);
	return 0;
}