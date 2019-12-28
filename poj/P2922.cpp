#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int t,n,k,a[120][120],L,R;
int v[120][120];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int in(int x,int y)
{
	return x>=0&&y>=0&&x<n&&y<n;
}
void dfs(int x,int y)
{
	if(a[x][y]<L||a[x][y]>R)
		return;
	v[x][y]=1;
	for(int k=0;k<4;k++)
	{
		int xx=x+dx[k],yy=y+dy[k];
		if(in(xx,yy)&&!v[xx][yy])
			dfs(xx,yy);
	}
}
int ok(int x)
{
	for(int i=0;i+x<=200;i++)
	{
		L=i,R=i+x;
		memset(v,0,sizeof v);
		dfs(0,0);
		if(v[n-1][n-1])
			return 1;
	}
	return 0;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",a[i]+j);
		int l=-1,r=200;
		for(;l<r-1;)
		{
			int m=l+r>>1;
			if(ok(m))
				r=m;
			else
				l=m;
		}
		printf("Scenario #%d:\n%d\n\n",++k,r);
	}
	return 0;
}
