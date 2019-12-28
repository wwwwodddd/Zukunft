#include<iostream>
#include<cmath>
using namespace std;
int n=2;
double g[205][205],d[205];
int st[205][2];
int x,y,i,j,k;
bool firstop=1;
double D(int* a,int* b)
{
  return sqrt(double((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])));
}
int main()
{
	scanf("%d%d%d%d",&st[0][0],&st[0][1],&st[1][0],&st[1][1]);
	g[0][1]=g[1][0]=D(st[0],st[1])/500*3;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		if(x==-1&&y==-1)
		{
			firstop=1;
			continue;
		}
		st[n][0]=x;
		st[n][1]=y;
		for(i=0;i<n;i++)
			g[n][i]=g[i][n]=D(st[i],st[n])/500*3;
		if(!firstop)
		 g[n][n-1]=g[n-1][n]=D(st[n],st[n-1])/2000*3;
		else
			firstop=0;
		n++;
	}
	for(k=0;k<n;k++)
		for(j=0;j<n;j++)
			for(i=0;i<n;i++)
				if(g[i][j]>g[i][k]+g[k][j])
					g[i][j]=g[i][k]+g[k][j];
	printf("%.0lf",g[0][1]);
	return 0;
}