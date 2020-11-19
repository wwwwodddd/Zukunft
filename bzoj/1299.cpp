#include<stdio.h>
int csc=10,i,n,v,a[20];
int dfs(int x,int y,int z)
{
	if(z==0&&y>0)
		return 1;
	if(x==n)
		return 0;
	return dfs(x+1,y,z)||dfs(x+1,y+1,z^a[x]);
}
int main()
{
	while(csc--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		puts(dfs(0,0,0)?"NO":"YES");
	}
	return 0;
}