#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int f[305][305][2];
int m[305],t[305];
int c[305],d[305];
int n;
int C(int x,int y)
{
	++y%=n;
	if(y<x)
		return c[x]-c[y];
	else
		return c[n]-c[y]+c[x];
}
int D(int x,int y)
{
	if(x>y)
		swap(x,y);
	return min(d[y]-d[x],d[x]+d[n]-d[y]);
}
int F(int x,int y,int z)
{
	if(x==y)
		return x?1000000000:0;
	int &t=f[x][y][z];
	if(~t)
		return t;
	int xx=(x+1)%n,yy=(y+n-1)%n;
	if(z)
		t=min(F(x,yy,0)+D(x,y)*C(x,yy),F(x,yy,1)+D(yy,y)*C(x,yy));
	else
		t=min(F(xx,y,0)+D(x,xx)*C(xx,y),F(xx,y,1)+D(x,y)*C(xx,y));
	return t;
}
int main()
{
	int i,j,k;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",m+i,t+i);
		for(i=0;i<n;i++)
			c[i+1]=c[i]+m[i],d[i+1]=d[i]+t[i];
		memset(f,-1,sizeof f);
		int z=min(F(0,n-1,0),F(0,n-1,1));
		for(i=1;i<n;i++)
			z=min(z,min(F(i,i-1,0),F(i,i-1,1)));
		printf("%d\n",z);
	}
}
