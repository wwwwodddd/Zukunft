#include<iostream>
using namespace std;
int g[520][520];
int a[520][5];
int v[520];
int l[520];
int t,n,x,y,ans;
int dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!v[i]&&g[x][i])
		{
			v[i]=1;
			if(l[i]==0||dfs(l[i]))
			{
				l[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int i,j;
	scanf("%d",&t);
	while(t--)
	{
		memset(g,0,sizeof(g));
		memset(l,0,sizeof(l));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d:%d %d %d %d %d",&x,&y,&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
			a[i][0]=x*60+y;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
					if(i!=j&&a[i][0]+abs(a[i][1]-a[i][3])+abs(a[i][2]-a[i][4])+abs(a[i][3]-a[j][1])+abs(a[i][4]-a[j][2])<a[j][0])
						g[i][j]=1;
		ans=0;
		for(i=1;i<=n;i++)
		{
			memset(v,0,sizeof(v));
			if(dfs(i))
				ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}