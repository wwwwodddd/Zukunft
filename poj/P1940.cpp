#include<stdio.h>
double p[1020][2];
int n,i;
int main()
{
	while(scanf("%d",&n)+1)
	{
		for(i=0;i<n;i++)
			scanf("%lf %lf",&p[i][0],&p[i][1]);
		p[n][0]=p[0][0];
		p[n][1]=p[0][1];
		printf("%d ",n);
		for(i=0;i<n;i++)
			printf("%.6lf %.6lf ",(p[i][0]+p[i+1][0])/2,(p[i][1]+p[i+1][1])/2);
		printf("\n");
	}
	return 0;
}