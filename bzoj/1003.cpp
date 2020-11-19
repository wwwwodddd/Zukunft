#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int a[105][105];
int c[105][105];
int v[105],d[105],f[105];
int i,j,k,l,m,n,x,y,z,e;
int dij(int x,int y)
{
	int i,j,k,mx;
	memset(v,0,sizeof(v));
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	for(i=x;i<=y;i++)
		for(j=1;j<=c[i][0];j++)
			v[c[i][j]]=1;
	for(i=1;i<n;i++)
	{
		mx=0x3f3f3f3f;
		for(j=1;j<=n;j++)
			if(!v[j]&&d[j]<mx)
				mx=d[k=j];
		if(v[k])
			return d[n];
		v[k]=1;
		for(j=1;j<=n;j++)
			d[j]=min(d[j],d[k]+a[k][j]);
	}
	return d[n];
}
int main()
{
	scanf("%d %d %d %d",&m,&n,&k,&e);
	memset(a,0x3f,sizeof(a));
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(i=1;i<=n;i++)
		a[i][i]=1;
	for(i=1;i<=e;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		a[y][x]=a[x][y]=min(a[x][y],z);
	}
	scanf("%d",&j);
	for(i=1;i<=j;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		for(l=y;l<=z;l++)
			c[l][++c[l][0]]=x;
	}
	for(i=1;i<=m;i++)
	{
		f[i]=0x3f3f3f3f;
		for(j=0;j<i;j++)
		{
			z=dij(j+1,i);
			if(z!=0x3f3f3f3f)
				f[i]=min(f[i],f[j]+z*(i-j)+k);
		}
	}
	printf("%d\n",f[m]-k);
	return 0;
}