#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1020];
int cmp(const void *x,const void *y)
{
	return *(int *)x-*(int *)y;
}
int fc(int z)
{
if(z>3)
	return min(2*a[1]+a[z]+a[z-1],a[1]+2*a[2]+a[z])+fc(z-2);
if(z==3)
	return a[3]+a[1]+a[2];
if(z==2)
	return max(a[2],a[1]);
if(z==1)
	return a[1];
}
int main()
{
	int t,i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		printf("%d\n",fc(n));
	}
	return 0;
}