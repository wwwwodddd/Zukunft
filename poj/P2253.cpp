#include<stdio.h>
#include<math.h>
int x[220],y[220];
int d[220];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j,k=0,n,f;
	while(scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
			scanf("%d %d",&x[i],&y[i]);
		f=1;
		d[1]=0;
		for(i=2;i<=n;i++)
			d[i]=0x3fffffff;	
		while(f)
		{
			f=0;
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(d[i]>max(d[j],(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])))
					{
						d[i]=max(d[j],(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
						f=1;
					}
		}
		printf("Scenario #%d\n",++k);
		printf("Frog Distance = %.3lf\n\n",sqrt((double)d[2]));
	}
	return 0;
}