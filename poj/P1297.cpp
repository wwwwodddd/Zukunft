#include<iostream>
using namespace std ;
int a[100002];
int b[101],i,j,k,m,n;
double c[100002];
double f[2][100002];
void clr(int x)
{
	for(int i=0;i<=n;i++)
		f[x][i]=1E30;
}
int main()
{
	while(scanf("%d %d",&m,&n),n+m)
	{
		for(i=1;i<=m;i++)
			scanf("%d",&b[i]);
		for(i=1;i<=n;i++)
			scanf("%d %lf",&a[i],&c[i]);
		memset(f,0,sizeof(f));
		for(i=k=1;k<=m;i=1-i,k++)
		{
			clr(i);
			for(j=k;j<=n;j++)
			{
				f[i][j]=f[i][j-1];
				if(b[k]==a[j])
					f[i][j]=min(f[i][j],f[1-i][j-1]+c[j]);
			}
		}
		if(f[m%2][n]>1E10)
			puts("Impossible");
		else
			printf("%.2f\n",f[m%2][n]);
	}
	return 0;
}