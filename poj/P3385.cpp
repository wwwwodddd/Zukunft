#include<stdio.h>
int i,n,d,x,z;
int f[100005];
int main()
{
	scanf("%d%d",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		f[x]++;
	}
	for(i=0;i<=n;i++)
		if(f[i]>d)
			z+=(f[i]-2)/(d-1);
	printf("%d\n",z);
	return 0;
}