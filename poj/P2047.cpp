#include<iostream>
#include<algorithm>
using namespace std;
int n,i,j,k;
int f[400][400];
struct N
{
	int s, e, w;
	bool operator<(const N &z)const
	{
		return e < z.e;
	}
}a[1100];
int main()
{
	while(scanf("%d",&n),n)
	{
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
			scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].w);
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			for(j=a[i-1].e+1;j<=a[i].e;j++)
				for(k=0;k<=a[i].e;k++)
				{
					f[j][k]=f[j-1][k];
					f[k][j]=f[k][j-1];
				}
			for(j=a[i].e;j>=0;j--)
			{
				f[a[i].e][j]=max(f[a[i].e][j],f[a[i].s-1][j]+a[i].w);
				f[j][a[i].e]=max(f[j][a[i].e],f[j][a[i].s-1]+a[i].w);
			}
		}
		printf("%d\n",f[a[n].e][a[n].e]);
	}
	return 0;
}