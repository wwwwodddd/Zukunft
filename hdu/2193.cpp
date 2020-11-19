#include<stdio.h>
int f[50]={1,2},i,n;
int main()
{
	for(i=2;i<43;i++)
		f[i]=f[i-1]+f[i-2]+1;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<43;i++)
			if(f[i+1]>n)
				break;
		printf("%d\n",i);
	}
	return 0;
}
