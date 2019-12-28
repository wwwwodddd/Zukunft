#include<stdio.h>
int e[12]={1,2,4,8,16,32,64,128,256,512,1024};
int a[1024][1024];
int n;
int main()
{
a[0][0]=1;
int i,j,k;
for(i=0;i<10;i++)
	{
	for(j=e[i];j<e[i+1];j++)
		for(k=e[i];k<e[i+1];k++)
			a[j][k]=a[j^e[i]][k^e[i]];
	for(j=0;j<e[i];j++)
		for(k=e[i];k<e[i+1];k++)
			a[j][k]=a[j][k^e[i]]+e[i+1];
	for(j=e[i];j<e[i+1];j++)
		for(k=0;k<e[i];k++)
			a[j][k]=a[j^e[i]][k]+e[i+1];
	for(int j=0;j<e[i];j++)
		a[e[i]+j][j]--;
	}
scanf("%d",&n);
for(int i=0;i<e[n];i++)
	{
	for(j=0;j<e[n];j++)
		printf("%d ",a[i][j]);
	printf("\n");
	}
return 0;
}