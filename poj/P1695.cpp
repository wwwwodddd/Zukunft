#include<stdio.h>
#include<string.h>
int m,n;
int i,j,k;
int s[31][31][31];
int g[31][31];
int min(int a,int b,int c)
{
int temp=a;
if(a>b)
   temp=b;
if(temp>c)
   temp=c;
return temp;
}
int main()
{
	scanf("%d",&m);
	while(m--)
	{
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		for( i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				scanf("%d",&g[i][j]);
		for(k=n-1;k>0;k--)
			for(i=1;i<=k;i++)
				for(j=1;j<=k;j++)
					s[i][j][k]=min(s[i][k][k+1]+g[j][k+1],s[j][k][k+1]+g[i][k+1],s[i][j][k+1]+g[k][k+1]);
		printf("%d\n",s[1][1][1]);
	}
	return 0;
}
