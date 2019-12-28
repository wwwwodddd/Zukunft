#include<stdio.h>
#include<string.h>
int a[510][510],l[510],v[510];
int dfs(int x)
{
	int i;
	for(i=1;i<=a[x][0];i++)
	{
		if(!v[a[x][i]])
		{
		v[a[x][i]]=1;
		if(l[a[x][i]]==-1||dfs(l[a[x][i]]))
			{
			l[a[x][i]]=x;
//			l[x]=a[x][i];
			return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int n,i,j,ans;
	while(scanf("%d",&n)!=EOF)
	{
		memset(l,-1,sizeof(l));
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d: (%d)",&i,&a[i][0]);
			for(j=1;j<=a[i][0];j++)
				scanf("%d",&a[i][j]);
		}
		for(i=0;i<n;i++)
		{
			memset(v,0,sizeof(v));
				if(dfs(i))
			ans++;
		}
		printf("%d\n",n-ans/2);
	}
	return 0;
}