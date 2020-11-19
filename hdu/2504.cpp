/*
  Name: 
  Copyright: 
  Author: 
  Date: 29-12-11 23:38
  Description: 
*/
#include<stdio.h>
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int i,csc,n,m;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d %d",&n,&m);
		n/=m;
		for(i=2;;i++)
			if(gcd(i,n)==1)
				break;
		printf("%d\n",i*m);	
	}
	return 0;	
}
//1A
