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
int FC(int z)
{
if(z>3)
{
	if(2*a[1]+a[z]+a[z-1]>a[1]+2*a[2]+a[z])
	{
		printf("%d %d\n",a[2],a[1]);
		printf("%d\n",a[1]);
		printf("%d %d\n",a[z],a[z-1]);
		printf("%d\n",a[2]);		
	}
	else
	{
		printf("%d %d\n",a[z],a[1]);
		printf("%d\n",a[1]);
		printf("%d %d\n",a[z-1],a[1]);
		printf("%d\n",a[1]);
	}
	return min(2*a[1]+a[z]+a[z-1],a[1]+2*a[2]+a[z])+FC(z-2);
}
if(z==3)
{
	printf("%d %d\n",a[3],a[1]);
	printf("%d\n",a[1]);
	printf("%d %d\n",a[2],a[1]);
	return a[3]+a[1]+a[2];
}
if(z==2)
{
	printf("%d %d\n",a[2],a[1]);
	return max(a[2],a[1]);
}
if(z==1)
{
	printf("%d\n",a[1]);
	return a[1];
}
}
int main()
{
	int t,i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	qsort(a+1,n,4,cmp);
	printf("%d\n",fc(n));
	FC(n);
	return 0;
}
