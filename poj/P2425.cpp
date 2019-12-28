#include<stdio.h>
#include<cstring>
int e[1005][1005];
int sg[1005];
int n,m,ans,x;
int SG(int n)
{
	if(sg[n]!=-1)
		return sg[n];
	if(e[n][0]==0)
		return sg[n]=0;
	int visit[1005];
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=e[n][0];i++)
		visit[SG(e[n][i])]=1;
	for(int i=0;i<=1000;i++)
		if(!visit[i])
			return sg[n]=i;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(sg,-1,sizeof(sg));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&e[i][0]);
			for(int j=1;j<=e[i][0];j++)
				scanf("%d",&e[i][j]);
		}
		for(int i=0;i<n;i++)
			sg[i]=SG(i);
		while(scanf("%d",&m)&&m)
		{
			ans=0;
			while(m--)
			{
				scanf("%d",&x);
				ans^=sg[x];
			}
			printf("%s\n",ans?"WIN":"LOSE");
		}
	}
	return 0;
}