#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int n,m,N;
double p,q;
double e[120][120];
int main()
{
	while(~scanf("%d %d %lf %lf",&n,&m,&p,&q))
	{
		memset(e,0,sizeof e);
		N=n+m+1;
		for(int i=0;i<N;i++)
		{
			if(i==0)
			{
				e[i][i]=1;
				e[i][N]=0;
			}
			else if(i==n+m)
			{
				e[i][i]=1;
				e[i][N]=1;
			}
			else
			{
				e[i][i-1]=q*(1-p);
				e[i][i+1]=p*(1-q);
				e[i][i]=p*q+(1-p)*(1-q)-1;
			}
		}
		for(int i=0;i<N;i++)
		{
			int p=i;
			for(int j=i+1;j<N;j++)
				if(fabs(e[j][i])>fabs(e[p][i]))
					p=j;
			for(int j=0;j<N;j++)
				swap(e[i][j],e[p][j]);
			for(int j=0;j<N;j++)
				if(j!=i)
				{
					double r=-e[j][i]/e[i][i];
					for(int k=0;k<=N;k++)
						e[j][k]+=r*e[i][k];
				}
		}
		printf("%.2lf\n",e[n][N]/e[n][n]);
	}
	return 0;
}
