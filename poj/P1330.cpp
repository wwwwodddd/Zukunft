#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int fa[10000],color[10000],head[10000],next[10000],v[10000];
int f[10000];
int suc;
int t,n,x,y,tot,ans,i;
int find(int x)
{
	if(x==fa[x])
		return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void tarjan(int u)
{
	int i;
	fa[u]=u;
	color[u]=1;
	i=head[u];
	while(i!=0)
	{
		if(color[v[i]]==0) 
		{
			tarjan(v[i]);
			if(suc)
				return;
			fa[v[i]]=u;
		}
		i=next[i];
	}
	if(u==x&&color[y]==2) 
	{
		ans=find(y);
		suc=1;
		return;
	}
	if(u==y&&color[x]==2) 
	{
		ans=find(x);
		suc=1;
		return;
	}
	color[u]=2;
}
int main()
{
scanf("%d",&t);
while(t--)
	{
	memset(f,0,sizeof(f));
	memset(fa,0,sizeof(fa));
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	memset(v,0,sizeof(v));
	memset(color,0,sizeof(color)); 
	tot=0;
	suc=0;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		f[y]=1;
		tot++;
		v[tot]=y;
		next[tot]=head[x];
		head[x]=tot;
	};
	scanf("%d %d",&x,&y);
	for(i=1;i<=n;i++)
		if(!f[i])
			tarjan(i);
	printf("%d\n",ans);
	}
return 0;
}
