#include<iostream>
using namespace std;
long long a[12][2005];
int x,y,t,i,j,k;
int main()
{
	for(i=1;i<2002;i++)
		a[1][i]=i;
	for(i=2;i<11;i++)
		a[i][(1<<(i-1))]=1;
	for(i=2;i<11;i++)
		for(j=(1<<(i-1))+1;j<2002;j++)
			a[i][j]=a[i][j-1]+a[i-1][j/2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		printf("Case %d: n = %d, m = %d, # lists = %I64d\n",++k,x,y,a[x][y]);
	}
return 0;
}
