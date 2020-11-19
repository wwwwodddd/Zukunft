#include<stdio.h>
#include<string.h>
int t,n,m,x,y,a[320][320];
int ok()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int x=0,y=0;
			for(int k=0;k<n;k++)
			{
				x|=a[i][k]&a[j][k];
				y|=a[i][k]^a[j][k];
			}
			if(x&y)
				return 0;
		}
	return 1;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		memset(a,0,sizeof a);
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
			scanf("%d%d",&x,&y),a[x][y]=1;
		puts(ok()?"Yes":"No");
	}
	return 0;
}
