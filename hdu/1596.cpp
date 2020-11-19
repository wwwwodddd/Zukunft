#include<stdio.h>
double f[1020][1020];
int n,q;
int main()
{
	int i,j,k,x,y;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%lf",f[i]+j);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(f[j][i]>1e-4) 
					for(k=1;k<=n;k++)
						if(f[j][k]<f[j][i]*f[i][k])
							f[j][k]=f[j][i]*f[i][k];
		scanf("%d",&q);
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			if(f[x][y]<1e-4)
				puts("What a pity!");
			else
				printf("%.3lf\n",f[x][y]);
		}
	}
	return 0;
}
