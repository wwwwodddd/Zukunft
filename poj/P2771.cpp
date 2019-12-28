#include<iostream>
using namespace std;
struct N{int h;char w,s[20],c[20];}p[505];
int v[505],l[505];
int g[505][505];
int t,n,i,j;
int dfs(int x)
{
	for(int i=1;i<=n;i++)
		if(g[x][i]&&!v[i])
		{
			v[i]=1;
			if(!l[i]||dfs(l[i]))
			{
				l[i]=x;
				return 1;
			}
		}
	return 0;
}
int S()
{
	int i,re=0;
	memset(l,0,sizeof(l));
	for(i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		if(dfs(i))
			re++;
	}
	return re;
}
int love(int x,int y)
{
	return !(abs(p[x].h-p[y].h)>40||p[x].w==p[y].w||strcmp(p[x].s,p[y].s)||strcmp(p[x].c,p[y].c)==0);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(g,0,sizeof(g));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d %c %s %s",&p[i].h,&p[i].w,p[i].s,p[i].c);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				g[i][j]=love(i,j);
		printf("%d\n",n-S()/2);
	}
	return 0;
}