#include<stdio.h>
int m[30][30];
int main()
{
	int n,s;
	int i,j;
	scanf("%d %d",&n,&s);
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
		{
			m[i][j]=s++;
			if(s>9)
				s=1;
		}
	for(i=1;i<=n;i++)
		{
		for(j=1;j<i;j++)
			printf("  ");	
		for(j=i;j<=n;j++)
			printf("%d ",m[j][i]);
		printf("\n");
		}
	return 0;
}