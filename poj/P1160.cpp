#include<stdio.h>
#include<string.h>
int f[310][310];
int w[310][310];
int s[310][310];
int v[310];
int n,m,i,j,k;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			w[i][j]=w[i][j-1]+v[j]-v[(j+i)/2];
	for(i=2;i<=m;i++)
		s[n+1][i]=n;
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(i=1;i<=m;i++)
		for(j=n;j>i;j--)
			for(k=s[j][i-1];k<=s[j+1][i];k++)
				if(f[j][i]>f[k][i-1]+w[k+1][j])
					f[j][i]=f[k][i-1]+w[k+1][j],s[j][i]=k;
	printf("%d\n",f[n][m]);
}