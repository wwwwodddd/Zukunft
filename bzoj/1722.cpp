#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define inf 0x3f3f3f3f;
int i,j,n,x,tot,z,l[512],w[512],h[512],f[512][2][512],a[512][2];
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
void F(int x)
{
	int i,y,j,k;
	for(i=h[x];i;i=a[i][0])
		F(a[i][1]);
	for(f[x][0][0]=0,f[x][1][0]=w[x],i=1;i<=n;i++)
		f[x][0][i]=f[x][1][i]=-inf;
	for(i=h[x];i;i=a[i][0])
		for(j=n;j>=0;j--)
			for(k=0;k+j<=n;k++)
			{
				f[x][0][k+j]=max(f[x][0][k+j],f[x][0][k]+f[a[i][1]][0][j]);
				f[x][0][k+j]=max(f[x][0][k+j],f[x][0][k]+f[a[i][1]][1][j]);
				f[x][1][k+j]=max(f[x][1][k+j],f[x][1][k]+f[a[i][1]][0][j]);
				f[x][1][k+j+1]=max(f[x][1][k+j+1],f[x][1][k]+f[a[i][1]][1][j]);
			}
}
int main()
{
	scanf("%d %d",&n,&x);
	w[0]=-inf;
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&w[i],&j);
		add(j,i);
	}
	F(0);
	for(i=n;i>0;i--)
		if(f[0][0][i]>=x||f[0][1][i]>=x)
			break;
	printf("%d\n",i);
	return 0;
}
