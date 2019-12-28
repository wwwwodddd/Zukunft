#include<iostream>
#include<math.h>
using namespace std;
double g[1020][1020];//权值
double p[1020][2];//点的坐标
double d[1020];
int v[1020];//点是否被访问过
int n,m;
double D(int x1,int y1,int x2,int y2)
{
	double x=x1-x2;
	double y=y1-y2;
	return sqrt(x*x+y*y);
}
double P()
{
	int i,j,k;
	double re=0;
	d[0]=10000000000000;
	for(i=1;i<=n;i++)
		d[i]=g[1][i];
	v[1]=true;
	for(i=1;i<n;i++)
	{
		k=0;
		for(j=1;j<=n;j++)
			if(!v[j]&&d[j]<d[k])
				k=j;
		v[k]=1;
		re+=d[k];
		for(j=1;j<=n;j++)
			if(!v[j]&&g[k][j]<d[j])
				d[j]=g[k][j];
	}
	return re;
}
int main()
{
	int i,j;
	int x,y;
	cin>>n>>m;
	for (i=1;i<=n;i++)
		cin>>p[i][0]>>p[i][1];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g[i][j]=D(p[i][0],p[i][1],p[j][0],p[j][1]);
	while(m--)
	{
		cin>>x>>y;
		g[x][y]=0;
		g[y][x]=0;
	}
	printf("%.2lf",P());
	return 0;
}