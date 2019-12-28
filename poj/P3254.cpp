#include<stdio.h>
int n,m,i,j,k,x,ans;
int f[15][4200];
int a[15];
void dfs(int w,int y,int z)
{
	if(w==n)
	{
		f[x][y]=(f[x][y]+f[x-1][z])%100000000;
		return;
	}
	if((a[x]>>w)&1&&w<=n-2)
	{
		dfs(w+2,y*4+2,z*4);
		dfs(w+2,y*4+2,z*4+1);
	}
	else if((a[x]>>w)&1)
		dfs(w+1,y<<1|1,z<<1);
	dfs(w+1,y<<1,z<<1|1);
	dfs(w+1,y<<1,z<<1);
	return;
}
int main()
{
	scanf("%d %d",&m,&n);
	f[0][0]=1;
	for(i=1;i<=m;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&x);
			a[i]=(a[i]<<1)+x;
		}
	for(i=1;i<=m;i++)
	{
		x=i;
		dfs(0,0,0);
	}
	for(i=0;i<(1<<n);i++)
		ans+=f[m][i];
	printf("%d",ans%100000000);
	return 0;
}