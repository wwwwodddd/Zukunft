#include<stdio.h>
#include<iostream>
using namespace std;
int p=100000007;
int c[2020][2020];
int n,m,x,y,t,na,nb,nc,nd,l;
long long z;
int main()
{
	c[0][0]=1;
	for(int i=1;i<2020;i++)
	{
		c[i][0]=1;
		for(int j=1;j<2020;j++)
		{
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			if(c[i][j]>=p)
				c[i][j]-=p;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&x,&y);
		na=m-y,nb=n-x,nc=y,nd=x-1;
		l=min(na,min(nb,min(nc,nd))+1);
		z=1;
		for(int i=1;i<=l;i++)
		{
			z+=(long long)c[na][i]*c[nb][i-1]%p*c[nc][i-1]%p*c[nd][i-1]%p;
			z+=(long long)c[na][i]*c[nb][i]%p*c[nc][i-1]%p*c[nd][i-1]%p;
			z+=(long long)c[na][i]*c[nb][i]%p*c[nc][i]%p*c[nd][i-1]%p;
			z+=(long long)c[na][i]*c[nb][i]%p*c[nc][i]%p*c[nd][i]%p;
			z%=p;
		}
		printf("%d\n",z);
	}
	return 0;
}