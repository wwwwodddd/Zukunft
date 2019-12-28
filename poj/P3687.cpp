#include<stdio.h>
#include<vector>
using namespace std;
int n,m;
int i,j,k;
int x,y,t;
int c[205],w[205];
vector<int>g[205];
vector<int>f[205];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<=n;i++)
		{
			c[i]=w[i]=0;
			g[i].clear();
			f[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			g[y].push_back(x);
			f[x].push_back(y);
			c[x]++;
		}
		for(i=n;i>0;i--)
		{
			for(j=n;j>0;j--)
				if(c[j]==0)
					break;
			if(j==0)
				break;
			for(k=0;k<g[j].size();k++)
				c[g[j][k]]--;
			c[j]++;
			w[j]=i;
		}
		if(i!=0)
			printf("-1\n");
		else
		{
			for(i=1;i<=n;i++)
				printf("%d ",w[i]);
			printf("\n");
		}
	}
	return 0;
}