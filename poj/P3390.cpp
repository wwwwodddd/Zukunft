#include<iostream>
using namespace std;
int n,m,t,i,j,z;
int a[10020];
int f[10020];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[0]=0x3fffffff;
		for(i=1;i<=n;i++)
		{
			f[i]=f[i-1]+(m-a[i])*(m-a[i]);
			for(j=i-1,z=a[i];a[j]+z+1<=m;j--)
			{
				z+=a[j]+1;
				f[i]=min(f[i],f[j-1]+(m-z)*(m-z));
			}
		}
		printf("%d\n",f[n]);
	}
	return 0;
}