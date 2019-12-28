#include<iostream>
#include<stdio.h>
using namespace std;
int b[250][250],a[250][250],c[250][250],n;
int main()
{
	int i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			c[i][j]=a[i][j];
			if(a[i][j]==0)
				b[i][j]=100000000;
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]!=0)
				for(k=1;k<=n;k++)
					for(l=1;l<=n;l++)
						if(i==k&&j==l)
							continue;
						else if(abs(k-i)+abs(l-j)==b[k][l])
							c[k][l]=0;
						else if(abs(k-i)+abs(l-j)<b[k][l])
						{
							b[k][l]=abs(k-i)+abs(l-j);
							c[k][l]=a[i][j];
						}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
				printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;
}
