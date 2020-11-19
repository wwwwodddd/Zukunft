#include<stdio.h>
int a[200000],z,n;
int main()
{
	while(scanf("%d",&n),n)
	{
		z=0;
		for(int i=0;i<n;i++)
			scanf("%d",a+i),z^=a[i];
		if(!z)
			puts("No");
		else
		{
			puts("Yes");
			for(int i=0;i<n;i++)
				if((z^a[i])<a[i])
					printf("%d %d\n",a[i],z^a[i]);
		}
	}
}
