#include<stdio.h>
#include<string.h>
struct N{int x,l,d,p;}a[11000];
int d[2220],g[2220],q[2220],v[2220],c[2220],h[2220],tot,n,m,s,t,z;
int b,f;
void add(int u,int v,int d,int l)
{
	if(h[u]&&d>a[h[u]].d)
		return;
	if(h[u]&&d<a[h[u]].d)
		h[u]=0;
	tot++;
	a[tot].x=v;
	a[tot].d=d;
	a[tot].l=l;
	a[tot].p=h[u];
	h[u]=tot;
}
int SPFA(int s)
{
	b=f=0;
	q[f++]=s;
	d[s]=g[s]=0;
	v[s]=c[s]=1;
	while(b!=f)
	{
		int x=q[b],y;
		b=(b+1)%2220;
		v[x]=0;
		if(c[x]>n+5)
			return 0;
		for(int p=h[x];p;p=a[p].p)
		{
			y=a[p].x;
			if(d[y]>d[x]+a[p].d||d[y]==d[x]+a[p].d&&g[y]>g[x]+a[p].l)
			{
				d[y]=d[x]+a[p].d;
				g[y]=g[x]+a[p].l;
				if(!v[y])
				{
					q[f]=y;
					f=(f+1)%2220;
					v[y]=1;
					c[y]++;
				}
			}
		}
	}
	return 1;
}
void dfs(int u)
{
	v[u]=1;
	if(u==t)
	{
		z=1;
		return;
	}
	for(int p=h[u];p;p=a[p].p)
		if(!v[a[p].x])
			dfs(a[p].x);
}
int main()
{
	int i,j,x,y,fxy,fyx,l,w;
	while(scanf("%d %d %d %d ",&n,&m,&s,&t)+1)
	{
		memset(d,0x33,sizeof(d));
		memset(g,0x33,sizeof(g));
		memset(v,0,sizeof(v));
		memset(c,0,sizeof(c));
		memset(h,0,sizeof(h));
		tot=0;
		for(i=0;i<m;i++)
		{
			scanf("(%d,%d,%d[%d]%d) ",&x,&y,&fxy,&l,&fyx);
			add(x,y,fxy,l);
			add(y,x,fyx,l);
		}
		w=SPFA(s);
		if(d[t]==0x33333333)
			printf("VOID\n");
		else if(w)
			printf("%d %d\n",d[t],g[t]);
		else
		{
			for(i=0;i<n;i++)
				if(c[i]>n)
				{
					memset(v,0,sizeof(v));
					z=0;
					dfs(i);
					if(z)
						break;
				}
			if(z||c[t]>n)
				printf("UNBOUND\n");
			else
				printf("%d %d\n",d[t],g[t]);
		}
	}
	return 0;
}