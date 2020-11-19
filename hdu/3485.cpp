#include<stdio.h>
int a[10020]={1,2,4,7},n;
int main()
{
	for(int i=4;i<10020;i++)
		a[i]=(a[i-1]+a[i-2]+a[i-4])%9997;
	while(scanf("%d",&n),n+1)
		printf("%d\n",a[n]);
	return 0;
}
