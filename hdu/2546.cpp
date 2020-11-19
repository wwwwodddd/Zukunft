#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int f[2020];
int a[2020],n,m,z;
int main()
{
	while(scanf("%d",&n),n)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		scanf("%d",&m);
		memset(f,0,sizeof f);
		f[0]=1;
		for(int i=0;i<n;i++)
			for(int j=m-5;j>=0;j--)
				f[j+a[i]]|=f[j];
		for(int j=0;j<=2000;j++)
			if(f[j])
				z=j;
		printf("%d\n",m-z);
	}
	return 0;
}
