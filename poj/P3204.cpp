#include<iostream>
using namespace std;
int d[502];
int g[502][502];
int r[502][502];
int c[502];
int p[502];
int v1[502];
int v2[502];
int n,m;
int ll,rr,ans;
int isap(int s,int t)
{
	int re=0,i=s,j,z;
	memset(p,-1,sizeof(p));
	p[s]=s;
	while(d[s]<m)
	{
		for(j=0;j<m;j++)
			if(g[i][j]>0&&d[i]==d[j]+1)
				break;
		if(j<m)
		{
			p[j]=i;
			i=j;
			if(i==t)
			{
				z=0x7fffffff;
				for(i=t;i!=s;i=p[i])
					z=min(z,g[p[i]][i]);
				for(i=t;i!=s;i=p[i])
					g[p[i]][i]-=z,g[i][p[i]]+=z;
				re+=z;
			}
		}
		else
		{
			c[d[i]]--;
			if(c[d[i]]==0)
				return re;
			d[i]=m;
			for(j=0;j<m;j++)
				if(g[i][j]>0)
					d[i]=min(d[i],d[j]+1);
			c[d[i]]++;
			i=p[i];
		}
	}
	return re;
}
void dfs1(int x)
{
	v1[x]=1;
	for(int i=0;i<m;i++)
		if(g[x][i]&&!v1[i])
			dfs1(i);
	return;
}
void dfs2(int x)
{
	v2[x]=1;
	for(int i=0;i<m;i++)
		if(g[i][x]&&!v2[i])
			dfs2(i);
	return;
}
int main()
{
	int i,j,x,y,z;
	ll=0x3fffffff;
	scanf("%d %d",&m,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		r[x][y]=1;
		g[x][y]+=z;
	}
	isap(0,m-1);
	dfs1(0);
	dfs2(m-1);
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			if(r[i][j]&&!g[i][j]&&v1[i]&&v2[j])
				ans++;
	printf("%d",ans);
	return 0;
}