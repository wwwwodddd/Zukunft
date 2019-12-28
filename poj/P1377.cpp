#include<stdio.h>
#include<iostream>
using namespace std;
int h[500020],tot;
int a[1000020][2];
int v[500020];
int f[500020][2];
int ans,n;
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
void F(int x)
{
	v[x]=1;
	f[x][0]=0;
	f[x][1]=1;
	for(int i=h[x];i;i=a[i][0])
		if(!v[a[i][1]])
		{
			F(a[i][1]);
			f[x][0]+=f[a[i][1]][1];
			f[x][1]+=f[a[i][1]][0];
		}
	f[x][0]=min(f[x][0],f[x][1]);
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		while(scanf("%d",&x),x)
			add(i,x);
	}
	for(int i=1;i<=n;i++)
		if(!v[i])
		{
			F(i);
			ans+=f[i][0];
		}
	printf("%d\n",ans-1);
	return 0;
}