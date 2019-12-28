#include<stdio.h>
#include<string.h>
int a[110][110];
int f[110][110];
int max(int a,int b)
{
return a>b?a:b;
}
int main()
{
int n,x,y,i,j;
while(scanf("%d",&n),n)
{
memset(a,0,sizeof(a));
memset(f,0,sizeof(f));
while(n--)
	{
	scanf("%d %d",&x,&y);
	a[x][y]++;
	}
for(i=0;i<=100;i++)
	for(j=0;j<=100;j++)
		f[i][j]=max(f[i][j-1],f[i-1][j])+a[i][j];
printf("%d\n",f[100][100]);
}
printf("*\n");
return 0;
}