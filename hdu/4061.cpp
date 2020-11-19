#include<stdio.h>
double z;
int n,x,y,t,k;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&x);
		for(z=x;--n;)
			scanf("%d",&y),z+=y;
		printf("Case %d: %.6f\n",++k,x/z);
	}
}
