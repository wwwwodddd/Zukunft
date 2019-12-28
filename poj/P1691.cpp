#include<stdio.h>
#include<string.h>
int y1[20],x1[20],y2[20],x2[20],c[20];
int a[20][20],d[20],v[20];
int t,n,ans;
void dfs(int x,int y,int z)
{
	if(y>=ans)
		return;
	if(x==n)
	{
		ans=y;
		return;
	}
	for(int i=0;i<n;i++)
		if(!v[i]&&!d[i])
		{
			v[i]=1;
			for(int j=0;j<n;j++)
				if(a[i][j])
					d[j]--;
			dfs(x+1,y+(c[i]!=z),c[i]);
			for(int j=0;j<n;j++)
				if(a[i][j])
					d[j]++;
			v[i]=0;
		}
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		memset(a,0,sizeof a);
		memset(d,0,sizeof d);
		memset(v,0,sizeof v);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d %d %d %d %d",y1+i,x1+i,y2+i,x2+i,c+i);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(y2[i]==y1[j]&&x1[j]<x2[i]&&x2[j]>x1[i])
				{
					d[j]++;
					a[i][j]=1;
				}
		ans=0xffff;
		dfs(0,0,0);
		printf("%d\n",ans);
	}
}
