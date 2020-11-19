#include<stdio.h>
#include<iostream>
using namespace std;
int a[1000020];
int n,t,x,y,z,u,k;
int sm;
int main()
{
	for(scanf("%d",&t);t--;printf("Case %d:\n%d %d\n%s",++k,y,z,t?"\n":""),y=z=u=0)
		for(scanf("%d",&n);n--;)
		{
			scanf("%d",&x);
			z+=max(x,0);
			if(x>0&&u==0)
				y++,u=1;
			if(x<0)
				u=0;
		}
}
