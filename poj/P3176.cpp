#include<stdio.h>
int a[400][400];
int f[400][400];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j;
	int n,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
	for(i=1;i<=n;i++)
		ans=max(ans,f[n][i]);
	printf("%d",ans);
	return 0;
}