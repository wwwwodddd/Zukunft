/*
  Name: 
  Copyright: 
  Author: 
  Date: 29-12-11 23:03
  Description: 
*/
#include<stdio.h>
int csc,n,m;
int k;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		printf("Scenario #%d:\n",++k);
		scanf("%d %d",&n,&m);
		if(n%2==1&&m%2==1)
			printf("%d.41\n",m*n);
		else
			printf("%d.00\n",m*n);
		printf("\n");
	}
	return 0;	
}
// jihaogongshi
// zhege juran yao wenmohuiche
