#include<stdio.h>
#include<string.h>
double f[100020];
int v[100020];
int n,m,x,y;
int main()
{
	while(scanf("%d %d",&n,&m),n)
	{
		memset(f,0,sizeof f);
		memset(v,0,sizeof v);
		for(int i=0;i<m;i++)
			scanf("%d %d",&x,&y),v[x]=y;
		for(int i=n-1;i>=0;i--)
			if(v[i])
				f[i]=f[v[i]];
			else
			{
				for(int j=1;j<=6;j++)
					f[i]+=f[i+j];
				f[i]/=6;
				f[i]++;
			}
		printf("%.4lf\n",*f);
	}
	return 0;
}
