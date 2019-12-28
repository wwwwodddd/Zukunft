#include<cstdio>
#include<string.h>
using namespace std;
int m,n,g[20][305];
int v[305];
int match()
{
	for(int i=0;i<n;i++)
		if(!v[i])
			return 0;
	return 1;
}
bool check(int row)
{
	for(int i=0;i<n;i++)
		if(v[i]&g[row][i])
			return 0;
	return true;
}
int dfs(int x)
{
	if(match())
		return 1;
	if(x==m)
		return 0;
	for(int i=x;i<m;i++)
		if(check(i))
		{
			for(int j=0;j<n;j++)
				if(g[i][j])
					v[j]=1;
			if(dfs(i+1))
				return 1;
			for(int j=0;j<n;j++)
				if(g[i][j])
					v[j]=0;
		}
	return 0;
}
int main()
{
	while(scanf("%d%d",&m,&n)+1)
	{
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&g[i][j]);
		memset(v,0,sizeof(v));
		if(dfs(0))
			printf("Yes, I found it\n");
		else
			printf("It is impossible\n");
	}
	return 0;
}
