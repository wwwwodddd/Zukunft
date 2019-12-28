#include<stdio.h>
#include<string.h>
int f[2][4000][2];
int u[4000];
int n,m,i,j,ans;
int max(int x,int y)
{
	return x>y?x:y;
}
void dp()
{
	for(i=2;i<=n;i++)
		for(j=0;j<=m;j++)
		{
			f[i&1][j][0]=max(f[1^i&1][j][0],f[1^i&1][j][1]);
			if(j!=0)
				f[i&1][j][1]=max(f[1^i&1][j-1][0],f[1^i&1][j-1][1]+u[i]);
		}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",u+i);
	if(m==0)
	{
		printf("0");
		return 0;
	}
	memset(f,0x80,sizeof(f));
	f[1][0][0]=f[1][1][1]=0;
	dp();
	ans=max(f[n&1][m][1],f[n&1][m][0]);
	memset(f,0x80,sizeof(f));
	f[1][1][1]=u[1];
	dp();
	ans=max(ans,f[n&1][m][1]);
	printf("%d",ans);
}
