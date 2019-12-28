#include<stdio.h>
#include<string.h>
#include<math.h>
const double eps=1e-5;
double d[1020];
double D[1020][1020];
int H[1020][1020];
int n;
int q[1020];
int v[1020];
struct P
{
int x,y,z;
}p[1020];
double U(int a,int b)
{
	return sqrt(1.*(p[a].x-p[b].x)*(p[a].x-p[b].x)+1.*(p[a].y-p[b].y)*(p[a].y-p[b].y));
}
int check(double x)
{
	memset(v,false,sizeof(v));
	int i,j,k;
	for(i=2;i<=n;i++)
	{
		d[i]=H[1][i]-D[1][i]*x;
		q[i]=1;
	}
	d[1]=0;
	v[1]=1;
	double dis=0,min,u;
	for(i=1;i<n;i++)
	{
		min=9E9;
		k=-1;
		for(j=2;j<=n;j++)
		{
			if(!v[j]&&d[j]<min)
			{
				min=d[j];
				k=j;
			}
		}
		v[k]=1;
		dis+=min;
		for(j=2;j<=n;j++)
		{
			u=H[k][j]-D[k][j]*x;
			if(!v[j]&&d[j]>u)
			{
				d[j]=u;
				q[j]=k;
			}
		}
	}
	if(dis<0)
		return 1;
	else
		return 0;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				D[i][j]=D[j][i]=U(i,j);
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				H[i][j]=H[j][i]=abs(p[i].z-p[j].z);
		double l=0,r=9E9;
		while(r-l>eps)
			if(check((r+l)/2))
				r=(r+l)/2;
			else
				l=(r+l)/2;
		printf("%.3f\n",l);
	}
	return 0;
}