#include<stdio.h>
int n,i,z;
int a[1000];
int main()
{
	while(scanf("%d",&n)&&n)
	{
		z=0;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		while(++z)
		{
			a[0]=a[n];
			for(i=n;i>0;i--)
			{
				a[i]=a[i]/2+a[i-1]/2;
				a[i]+=a[i]%2;
			}
			for(i=1;i<=n;i++)
				if(a[i]!=a[n])
					break;
			if(i>n)
				break;
		}
		printf("%d %d\n",z,a[n]);
	}
	return 0;
}
