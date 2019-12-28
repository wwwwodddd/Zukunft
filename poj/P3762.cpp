#include<stdio.h>
#include<string.h>
#include<iostream>
#define inf 0x3f3f3f3f
using namespace std;
int e[200020][4];
int h[4020];
int a[4020];
int b[4020];
int d[4020];
int w[4020];
int v[4020];
int p[4020];
int l[100010];
int c[100010];
int q[1000010],bb,ff;
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
int scan()
{
	int x,y,z;
	scanf("%d:%d:%d",&x,&y,&z);
	return x*3600+y*60+z+1;
}
int main()
{
	int i,k;
	tot=1;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		a[i]=scan();
		b[i]=scan();
		scanf("%d",&w[i]);
		l[a[i]]=l[b[i]]=1;
	}
	for(i=0;i<100010;i++)
		if(l[i])
			c[i]=++m;
	s=0;
	t=m+1;
	add(s,1,k,0);
	add(m,t,k,0);
	for(i=1;i<m;i++)
		add(i,i+1,k,0);
	for(i=0;i<n;i++)
		add(c[a[i]],c[b[i]],1,w[i]);
	while(spfa())
		ek();
	printf("%d\n",ans);
	return 0;
}