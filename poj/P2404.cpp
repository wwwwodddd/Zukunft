#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
int d[20][20],v[20],f[65537];
int n,m,ans;
int F(int x)
{
	if(f[x]!=0x3f3f3f3f)
		return f[x];
	int &t=f[x],y;
	for(y=0;y<n;y++)
		if(x>>y&1)
			break;
	for(int i=y+1;i<n;i++)
		if(x>>i&1)
			t=min(t,d[y][i]+F(x^1<<i^1<<y));
	return t;
}
int main()
{
	int x,y,z;
	for(;scanf("%d %d",&n,&m),n;)
	{
		ans=0;
		memset(v,0,sizeof v);
		memset(d,0x3f,sizeof d);
		memset(f,0x3f,sizeof f);
		fr(i,m)
		{
			scanf("%d %d %d",&x,&y,&z);
			v[--x]^=1,v[--y]^=1;
			d[x][y]=d[y][x]=min(d[x][y],z);
			ans+=z;
		}
		fr(k,n)
			fr(i,n)
				fr(j,n)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		f[0]=x=0;
		fr(i,n)
			x|=v[i]<<i;
		printf("%d\n",ans+F(x));
	}
	return 0;
}
