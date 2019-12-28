#include<iostream>
using namespace std;
int n,a[10001][2],p,f[1001],z,ans;
int i,j,r;
int main()
{
	while(scanf("%d%d",&n,&p)+1)
	{
		for(i=1;i<=p;i++)
		{
			scanf("%d%d",&a[i][0],&a[i][1]);
			if(a[i][0]>a[i][1])
				swap(a[i][0],a[i][1]);
		}
		ans=0xffffff;
		for(i=1;i<=n;i++)
		{
			memset(f,0,sizeof(f));
			for(j=1;j<=p;j++)
				if(a[j][0]<i&&a[j][1]>=i)
				{
					f[1]=max(f[1],a[j][0]);
					f[a[j][1]]=max(f[a[j][1]],n+1);
				}
				else
					f[a[j][0]]=max(f[a[j][0]],a[j][1]);
			z=r=0;
			for(j=1;j<=n;j++)
				if(f[j])
				{
					if(j>r)
					{
						z+=f[j]-j;
						r=f[j];
					}
					else if(f[j]>r)
					{
						z+=f[j]-r;
						r=f[j];
					}
					if(z>ans)
						break;
				}
			ans=min(ans,z);
		}
		printf("%d\n",ans);
	}
	return 0;
}
