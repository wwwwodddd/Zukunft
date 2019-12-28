#include <stdio.h>
int i,n1,n2,x1,y1,z1,x2,y2,z2;
int abs(int x)
{
	return x>0?x:-x;
}
int main()
{
	while(scanf("%d%d",&n1,&n2)+1) 
	{
		x1=x2=1;
		for(i=1;n1>0;i=i+2)
		{
			y1=(i-n1)/2+1;
			z1=(n1+1)/2;
			x1++;
			n1=n1-i;
		}
		for(i=1;n2>0;i=i+2)
		{
			y2=(i-n2)/2+1;
			z2=(n2+1)/2;
			x2++;
			n2=n2-i;
		}
		printf("%d\n",abs(x1-x2)+abs(z1-z2)+abs(y1-y2));
	}
}