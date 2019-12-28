#include<stdio.h>
#include<string.h>
#define INF 0x3fffffff
int a[105][10010];
int b[105][105][2];//[0]:band;[1]:price;
int g[105];
int n;
int i,j,k,x,l;
int max,min;
double ans;
void print()
{
int i,j;
for(i=1;i<=n;i++)
{
	for(j=1;j<=max;j++)
		printf("%4d",a[i][j]);
	printf("\n");
}
printf("\n");
return;
}
int main()
{
scanf("%d",&l);
while(l--)
	{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(g,0,sizeof(g));
	scanf("%d",&n);
	min=INF;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&g[i]);
		for(j=1;j<=g[i];j++)
		{ 
			scanf("%d %d",&b[i][j][0],&b[i][j][1]); 
			if(b[i][j][0]>max)  
				max=b[i][j][0];
			if(b[i][j][0]<min)
				min=b[i][j][0];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=max;j++)
			a[i][j]=INF;
	}
	for(j=1;j<=g[1];j++)
		{
		if(a[1][b[1][j][0]]>b[1][j][1])
			a[1][b[1][j][0]]=b[1][j][1];
		}
	for(i=2;i<=n;i++)
	{
		for(k=min-1;k<=max;k++)
		{
			if(a[i-1][k]!=INF) 
				for(j=1;j<=g[i];j++)
				{
					x=k;
					x>b[i][j][0]?x=b[i][j][0]:0;
					a[i][x]=a[i][x]<a[i-1][k]+b[i][j][1]?a[i][x]:a[i-1][k]+b[i][j][1];
				}
		}
	}
	ans=0;
	for(i=1;i<=max;i++)
		{
		if(ans<double(i)/a[n][i])
			ans=double(i)/a[n][i];
		}
	printf("%.3lf\n",ans);
	}
return 0;
}