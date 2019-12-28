#include<stdio.h>
int t,i,n,f[75000];
int main()
{
	f[0]=f[1]=1;
	for(i=2;i<75000;i++)
		f[i]=(3*f[i-1]-f[i-2]+100000)%100000;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",f[n%75000]);
	}
	return 0;
}