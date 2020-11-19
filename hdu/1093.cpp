/*
  Name: 
  Copyright: 
  Author: 
  Date: 29-12-11 23:12
  Description: 
*/
#include<stdio.h>
int n,m,x,sum,i;
int main()
{
	scanf("%*d");
	while(scanf("%d",&n)+1)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			sum+=x;
		}
		printf("%d\n",sum);
	}
	return 0;	
}
//zhuyigai jieshutiaojian 
