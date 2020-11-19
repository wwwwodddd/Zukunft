/*
  Name: 
  Copyright: 
  Author: 
  Date: 30-12-11 00:00
  Description: 
*/
#include<stdio.h>
int n,x;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		printf("%d\n",(x%10000)*(x%10000)%10000);
	}
	return 0;	
}
// kan cuo mod shu le 
