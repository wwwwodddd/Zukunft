/*
  Name: 
  Copyright: 
  Author: 
  Date: 30-12-11 00:13
  Description: 
*/
#include<stdio.h>
#include<iostream>
using namespace std;
int n,x,i;
int main()
{
	while(scanf("%d",&n),n)
	{
		x=0;
		while(n--)
		{
			scanf("%d",&i);
			x=max(i,x);
		}
		printf("%d\n",x);
	}
	return 0;	
}
//1A
