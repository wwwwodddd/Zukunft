#include<stdio.h>
#include<string.h>
struct Edge{int v,w,p;}e1[80020],e2[20020];
int h1[40010],h2[40010],f[40010],d[40010];
int ans[10010],v[40010];
int n,m,cnt1,cnt2;
int i,k,x,y,w;
char s[5];
void add1(int u,int v,int w)
{
	cnt1++;
	e1[cnt1].v=v;
	e1[cnt1].w=w;
	e1[cnt1].p=h1[u];
	h1[u]=cnt1;
}
void add2(int u,int v,int w)
{
	cnt2++;
	e2[cnt2].v=v;
	e2[cnt2].w=w;
	e2[cnt2].p=h2[u];
	h2[u]=cnt2;
}
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
void tarjan(int u,int w)
{
	int i;
	d[u]=w;
	v[u]=1;
	for(i=h2[u];i;i=e2[i].p)
		if(v[e2[i].v])
			ans[e2[i].w]=d[u]+d[e2[i].v]-2*d[F(e2[i].v)];
	for(i=h1[u];i;i=e1[i].p)
	{
		if(!v[e1[i].v])
		{
			tarjan(e1[i].v,w+e1[i].w);
			f[e1[i].v]=u;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=1;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&w);
		add1(x,y,w);
		add1(y,x,w);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add2(x,y,i);
		add2(y,x,i);
	}
	tarjan(1,0);
	for(i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}