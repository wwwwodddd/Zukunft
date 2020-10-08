#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int y[50010];
int r[50010];
int n;
inline int lg(int x)
{
	if(x==1)
		return 0;
	return lg(x/2)+1;
}
int f[18][50010];
int rmq(int a,int b)
{
	if (a > b)
		return 0;
	int k = 31 - __builtin_clz(b-a+1);
	return max(f[k][a],f[k][b+1-(1<<k)]);
}
int main()
{
	int q,a,b,ra,rb,mx;
	scanf("%d",&n);
	y[0]=0x80000000;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&y[i],&r[i]);
		f[0][i]=r[i];
	}
	for(int i=1;1<<i<=n;i++)
	{
		for(int j=0;j+(1<<i)-1<=n;j++)
		{
			f[i][j]=max(f[i-1][j],f[i-1][j+(1<<i-1)]);
		}
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d%d", &a, &b);
		ra=lower_bound(y,y+n+1,a)-y;
		rb=lower_bound(y,y+n+1,b)-y;
		if(y[ra]!=a&&y[rb]!=b)
		{
			puts("maybe");
		}
		else if(y[ra]==a&&y[rb] != b)
		{
			puts(rmq(ra+1,rb-1) < r[ra] ? "maybe" : "false");
		}
		else if(y[ra]!=a&&y[rb]==b)
		{
			puts(rmq(ra,rb-1) < r[rb] ? "maybe" : "false");
		}
		else if(y[ra]==a&&y[rb]==b)
		{
			if(r[rb]<=r[ra] && rmq(ra+1,rb-1)<r[rb])
			{
				puts(rb-ra==b-a?"true":"maybe");
			}
			else
			{
				puts("false");
			}
		}
	}
	return 0;
}