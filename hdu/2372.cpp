#include<stdio.h>
#include<string.h>
long long f[120][120],z;
int n,m,a[10020];
int main()
{
	while(scanf("%d%d",&n,&m),n+m)
	{
		a[0]=-1<<30;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		memset(f,0,sizeof f);
		z=0;
		f[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<i;j++)
				for(int k=0;k<m;k++)
					if(a[j]<a[i])
					f[i][k+1]+=f[j][k];
			z+=f[i][m];
		}
		printf("%I64d\n",z);
	}
	return 0;
}
