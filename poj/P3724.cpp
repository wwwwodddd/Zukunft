#include<stdio.h>
#include<math.h>
int n,z[11],v[11];
double x[21],y[21];
bool fg;
void dfs(int p,int q)
{
	if(fg)
		return;
	if(p>=10)
	{
		int i;
		for(i=0;i<n;i++)
		{
			double s=0;
			for(int j=0;j<10;j++)
				s+=exp(v[j]*x[i]);
			if(fabs(s/y[i]-1)>1e-4)
				break;
		}
		if(i>=n)
		{
			for(int j=0;j<10;j++)
				z[j]=v[j];
			fg=true;
		}
		return;
	}
	for(int i=q;i<=10;i++)
	{
		v[p]=i;
		dfs(p+1,i);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%lf%lf",x+i,y+i);
	dfs(0,0);
	for(int i=0;i<10;i++)
		printf("%d\n",z[i]);
	return 0;
}
