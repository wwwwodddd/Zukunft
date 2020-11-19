/*
  Name: 
  Copyright: 
  Author: 
  Date: 29-12-11 23:42
  Description: 
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[200];
int n,csc,i;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);	
		sort(a,a+n);
		printf("%d\n",a[1]);
	}
	return 0;
}
//1A
