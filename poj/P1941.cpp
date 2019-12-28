#include<stdio.h>
#include<string.h>
char a[5000][5000],c;
int e[12]={1,2,4,8,16,32,64,128,256,1024,2048,4096};
int main()
{
	int i,j,k;
	int n;
	memset(a,' ',sizeof(a));
	a[0][0]=a[1][1]='/';
	a[0][1]=a[0][2]='_';
	a[0][3]=a[1][2]='\\';
	for(i=2;i<11;i++)
		for(j=0;j<e[i-1];j++)
			for(k=0;k<e[i];k++)
			{
				a[j+e[i-1]][k+e[i-1]]=a[j][k];
				a[j][k+e[i]]=a[j][k];
			}
	while(scanf("%d",&n)&&n!=0)
	{
		for(i=e[n]-1;i>=0;i--)
		{
			c=a[i][e[n+1]];
			a[i][e[n+1]]=0;
			printf("%s\n",a[i]);
			a[i][e[n+1]]=c;
		}
		printf("\n");
	}
	return 0;
}
