#include<stdio.h>
#include<math.h>
int xa,ya,xb,yb;
int main()
{
	while(scanf("%d %d %d %d",&xa,&ya,&xb,&yb)+1)
		printf("%.2lf\n",sqrt((double)(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)));
}