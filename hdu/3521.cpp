#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
double a[120][120],b[120][120],c[120][120];
int n;
void add()
{
	fr(i,n)
		fr(j,n)
			b[i][j]+=c[i][j];
}
void mul(int x)
{
	double d[120][120];
	memset(d,0,sizeof d);
	fr(i,n)
		fr(j,n)
			fr(k,n)
				d[i][j]+=c[i][k]*a[k][j];
	fr(i,n)
		fr(j,n)
			c[i][j]=d[i][j]/x;
}
int main()
{
	for(;scanf("%d",&n),n;)
	{
		memset(b,0,sizeof b);
		fr(i,n)
			fr(j,n)
				scanf("%lf",&a[i][j]);
		fr(i,n)
			fr(j,n)
				b[i][j]=c[i][j]=i==j;
		fo(k,50)
		{
			mul(k);
			add();
		}
		fr(i,n)
		{
			fr(j,n)
				printf("%.2f ",b[i][j]);
			puts("");
		}
	}
}
