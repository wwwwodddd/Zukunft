#include<stdio.h>
int i,n,f[50020];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&f[i]);
	for(i=1;i<=n;i++)
		if(f[i]>=f[i-1]&&f[i]>=f[i+1])
			printf("%d\n",i);
	return 0;
}

