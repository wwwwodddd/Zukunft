#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int f[100020],w[120],c[120],n,m,z;
void mk(int x)
{
	for(int i=m;i>=x;i--)
		if(f[i-x])
			f[i]=1;
}
int main()
{
	while(scanf("%d%d",&n,&m),n+m)
	{
		memset(f,0,sizeof f);
		z=0;
		f[0]=1;
		for(int i=0;i<n;i++)
			scanf("%d",w+i);
		for(int i=0;i<n;i++)
			scanf("%d",c+i);
		for(int i=n-1;i>=0;i--)
			for(int j=0;c[i];j++)
			{
				int t=min(1<<j,c[i]);
				mk(t*w[i]);
				c[i]-=t;
			}
		for(int i=1;i<=m;i++)
			z+=f[i];
		printf("%d\n",z);
	}
	return 0;
}
