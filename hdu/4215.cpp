#include<iostream>
#include<stdio.h>
using namespace std;
int a[31]={0,1,1,2,2,4,5,5,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,9,9,9,9,9,9,10};
int main()
{
	int n,m,t;
	scanf("%d",&n);
	for(t=1;t<=n;t++)
	{
		scanf("%d",&m);
		printf("Case %d: %d\n",t,a[min(30,m)]);
	}
}
