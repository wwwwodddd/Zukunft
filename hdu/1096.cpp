/*
  Name: 
  Copyright: 
  Author: 
  Date: 29-12-11 23:14
  Description: 
*/
#include<stdio.h>
int n,m,x,sum,i,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			sum+=x;
		}
		printf("%d\n",sum);
		if(t)
			printf("\n");
	}
	return 0;	
}
//wenmo \n
