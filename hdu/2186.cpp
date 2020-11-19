#include<stdio.h>
int n,t,x,y,z;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n) ;
		x=n/2 ;
		y=(n-x)*2/3;
		z=n-x-y;
		printf("%d\n",(x+9)/10+(y+9)/10+(z+9)/10);
	}
	return 0;
}
