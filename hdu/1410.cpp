#include<stdio.h>
#include<math.h>
double z,d;
int h1,h2,a1,a2;
int main()
{
	while(~scanf("%d %d %d %d",&h1,&h2,&a1,&a2))
	{
		z=d=0;
		h1=(h1+a2-1)/a2;
		h2=(h2+a1-1)/a1;
		z=pow(.5,h2);
		for(int i=1;i<h1;i++)
		{
			d+=log(h2-1+i)-log(i);
			z+=exp(d+(h2+i)*log(.5));
		}
		printf("%.4lf\n",z*100);
	}
	return 0;
}
