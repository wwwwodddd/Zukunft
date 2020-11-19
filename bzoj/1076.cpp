#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
double f[102][65537];
int i,j,k,n,m,t;
int v[22],d[22];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",v+i);
		for(;scanf("%d",&t),t;)
			d[i]+=1<<t-1;
	}
	for(i=n;i;i--)
		for(j=0;j<1<<m;j++)
		{
			f[i][j]=0;
			for(k=0;k<m;k++)
				if((d[k]&j)==d[k])
					f[i][j]+=max(f[i+1][j],f[i+1][j|1<<k]+v[k]);
				else
					f[i][j]+=f[i+1][j];
			f[i][j]/=(double)k;
		}
	printf("%.6lf\n",f[1][0]);
	return 0;
}