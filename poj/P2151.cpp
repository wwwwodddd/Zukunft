#include<stdio.h>
#include<string.h>
int m,n,t,i,j,k;
double p,p1,p2,px;
double f[33];
int main()
{
	while(scanf("%d%d%d",&m,&t,&n)&&m+n+t)
	{
		p1=1;
		p2=0;
		for(i=1;i<=t;i++)
		{
			memset(f,0,sizeof(f));
			f[0]=1;
			for(j=1;j<=m;j++)
			{
				scanf("%lf",&p);
				for(k=j;k>0;k--)
					f[k]=f[k-1]*p+f[k]*(1-p);
				f[0]*=1-p;
			}
			for(j=n,px=0;j<=m;j++)
				px+=f[j];
			p2=(1-f[0])*p2+p1*px;
			p1*=1-px-f[0];
		}
		printf("%.3lf\n",p2);
	}
	return 0;
}