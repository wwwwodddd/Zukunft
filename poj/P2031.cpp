#include<iostream>
#include<math.h>
using namespace std;
double a[105][4];
double g[105][105];
double d[105];
int v[105];
int n,y;
double ans;
double u,x;
void prim()
{
	int i,j,k;
	memset(v,0,sizeof(v));
	for(i=1;i<n;i++)
		d[i]=g[0][i];
	v[0]=1;
	for(k=1;k<n;k++)
	{
		x=1E9;
		for(j=1;j<n;j++)
			if(!v[j]&&x>d[j])
			{
				x=d[j];
				y=j;
			}
		v[y]=1;
		ans+=d[y];
		d[y]=0;
		for(i=0;i<n;i++)
			if(d[i]>g[y][i])
				d[i]=g[y][i];
	}
}
int main()
{
	int i,j;
	while(scanf("%d",&n)&&n)
	{
		ans=0;
		for(i=0;i<n;i++)
			scanf("%lf %lf %lf %lf",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				double u=sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1])+(a[i][2]-a[j][2])*(a[i][2]-a[j][2]))-a[i][3]-a[j][3];
				if(u<0)
					g[i][j]=g[j][i]=0;
				else
					g[i][j]=g[j][i]=u;
			}
		prim();
		printf("%.3lf\n",ans);
	}
	return 0;
}
