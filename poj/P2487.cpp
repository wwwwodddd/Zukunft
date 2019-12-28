#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
int a[1005],sum;
int t,n,m,i,j,k;
int cmp(const void *a, const void *b)
{ 
	return *(int*)b-*(int*)a;
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		for(j=0;j<n;j++)
			scanf("%d", &a[j]);
		qsort(a,n,4,cmp);
		sum=0;
		for (j=0;j<n;j++)
		{
			sum+=a[j];
			if(sum>=m)
				break;
		} 
		printf("Scenario #%d:\n",++k);
		if(sum>=m) 
			printf("%d\n\n",j+1);
		else
			printf("impossible\n\n");
		}
	return 0;
}