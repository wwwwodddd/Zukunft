#include<stdio.h>
int n;
int v[1000020];
int main()
{
	for(int i=0;i<=100;i++)
		v[i*i*i]=i;
	while(scanf("%d",&n),n)
	{
		for(int i=0;i*i*i<n;i++)
			if(v[n-i*i*i])
			{
				printf("%d %d\n",i,v[n-i*i*i]);
				goto end;
			}
		puts("Impossible");
		end:;
	}
	return 0;
}
