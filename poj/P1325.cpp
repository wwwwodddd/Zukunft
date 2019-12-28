#include<stdio.h>
#include<string.h>
int a[210][110];
int l[210];
int v[210];
int n,x,y,ans;
int dfs(int x)
{
int i;
for(i=1;i<=a[x][0];i++)
	if(!v[a[x][i]])
	{
		v[a[x][i]]=1;
		if(l[a[x][i]]==0||dfs(l[a[x][i]]))
		{
			l[a[x][i]]=x;
			return 1;
		}
	}
return 0;
}

int main()
{

	int i,j,k,q,w,e;
	while(scanf("%d",&x)&&x!=0)
	{
		scanf("%d %d",&y,&n);
		ans=0;
		memset(l,0,sizeof(l));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
		{
			scanf("%d %d %d",&q,&w,&e);
			if(w==0||e==0)
				continue;
			e+=x;
			a[w][++a[w][0]]=e;
			a[e][++a[e][0]]=w;
		}
		for(i=1;i<x;i++)
		{
			memset(v,0,sizeof(v));
			if(dfs(i))
				ans++;
		}
		printf("%d\n",ans);
	}
return 0;
}
