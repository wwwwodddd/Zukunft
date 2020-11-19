#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
int n,m,o,x,y,csc;
long long c[100020];
long long a[100020];
int f[100020];
void R(int x,long long y)
{
	for(;x<=n;x+=x&-x)
		c[x]+=y;
}
long long G(int x)
{
	long long re=0;
	for(;x;x-=x&-x)
		re+=c[x];
	return re;
}
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		for(int i=1;i<=n;i++)
			scanf("%lld",a+i),c[i]=a[i];
		for(int i=1;i<=n;i++)
			if(i+(i&-i)<=n)
				c[i+(i&-i)]+=c[i];
		for(int i=1;i<=n+5;i++)
			f[i]=i;
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&o);
			scanf("%d %d",&x,&y);
			if(x>y)
				swap(x,y);
			if(o)
			{
				printf("%lld\n",G(y)-G(x-1));
			}
			else
			{
				for(int i=F(x);i<=y;i=F(i+1))
				{
					long long u=(long long)sqrt((double)a[i]);
					R(i,u-a[i]);
					a[i]=u;
					if(u==1)
						f[i]=i+1;
				}
			}
		}
		puts("");
	}
	return 0;
}
