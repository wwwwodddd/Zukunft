#include"stdio.h"
int a[100][100];
int main()
{
int n,m,i=0,j,k=80;
a[0][0]=a[1][0]=1;
for(i=2;i<100;i++)
	{
	for(j=0;j<90;j++)
		a[i][j]=a[i-1][j]+a[i-2][j];
	for(j=0;j<90;j++)
		{
		a[i][j+1]+=a[i][j]/10;
		a[i][j]%=10;
		}
	}
scanf("%d",&m);
i=1;
while(m--)
	{
	scanf("%d",&n);
	n++;
	k=80;
	while(!a[n][k])
		k--;
	printf("Scenario #%d:\n",i++);
	for(;k>=0;k--)
		printf("%d",a[n][k]);
	printf("\n\n");
	}
return 0;
}