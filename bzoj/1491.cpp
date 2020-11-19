#include<stdio.h>
#include<string.h>
#include<iostream>
#define fo(i,n) for(int i=1;i<=n;i++)
using namespace std;
int d[120][120];
double p[120][120];
int main()
{
	int n,m,x,y,z;
	scanf("%d %d",&n,&m);
	memset(d,0x3f,sizeof d);
	fo(i,n)
		fo(j,n)
			p[i][j]=1;
	fo(i,n)
		d[i][i]=p[i][i]=0;
	fo(i,m)
	{
		scanf("%d %d %d",&x,&y,&z);
		d[x][y]=d[y][x]=min(d[x][y],z);
	}
	fo(k,n)
		fo(i,n)
			fo(j,n)
			{
				
				if(d[i][k]+d[k][j]<d[i][j])
				{
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=p[i][k]*p[k][j];
				}
				else if(d[i][k]+d[k][j]==d[i][j])
					p[i][j]+=p[i][k]*p[k][j];
			}
	fo(k,n)
	{
		double z=0;
		fo(i,n)
			fo(j,n)
				if(i!=k&&j!=k)
					if(d[i][k]+d[k][j]==d[i][j])
						z+=(double)p[i][k]*p[k][j]/p[i][j];
		printf("%.3f\n",z);
	}
	return 0;
}
