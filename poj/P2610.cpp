#include<stdio.h>
double x1,y1,x2,y2,x3,y3;
int main()
{
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	while(scanf("%lf %lf",&x3,&y3)!=EOF)
	if(4*((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))<(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2))
	{
		printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",x3,y3);
		return 0;
	}
	printf("The gopher cannot escape.\n");
	return 0;
}
