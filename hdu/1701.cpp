#include<stdio.h>
int t;
double n,m;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%lf %lf",&m,&n);
		for(int i=1;;i++)
			if((int )(i*m*.01)<(int )(i*n*.01))
			{   
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
