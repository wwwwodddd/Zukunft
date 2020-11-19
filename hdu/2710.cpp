#include<stdio.h>
int f[20020],i,j,x,n,z;
int main()
{
	for(i=2;i<20010;i++)
		if(!f[i])
			for(j=i;j<20010;j+=i)
				f[j]=i;
	while(scanf("%d",&n)+1)
	{
		z=1;
		while(n--)
		{
			scanf("%d",&x);
			f[z]<f[x]?z=x:0;
		}
		printf("%d\n",z);
	}
	return 0;
}