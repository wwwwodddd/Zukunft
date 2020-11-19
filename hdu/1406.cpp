#include<stdio.h>
#include<iostream>
using namespace std;
int a[4]={6,28,496,8128},n,m,i,z,csc;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d%d",&n,&m);
		z=0;
		if(n>m)
			swap(n,m);
		for(i=0;i<4;i++)
			if(a[i]<=m&&a[i]>=n)
				z++;
		printf("%d\n",z);
	}
	return 0;
}