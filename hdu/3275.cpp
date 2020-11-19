#include<stdio.h>
int i,n,k,z;
int a[100020];
int b[100020];
int main()
{
	while(scanf("%d%d",&n,&k),n)
	{
		z=0;
		for(i=*a=1;i<=n;i++)
			scanf("%1d",a+i);
		if(k==0)
		{
			for(i=1;i<=n;i++)
				if(!a[i])
					break;
			printf("%d\n",(i>n)-1);
			continue;
		}
		for(i=1;i<=n;i++)
			b[i]=a[i]^a[i-1];
		for(i=1;i<=n-k+1;i++)
			if(b[i])
				b[i]^=1,b[i+k]^=1,z++;
		for(i=n-k+2;i<=n;i++)
			if(b[i])
				break;
		printf("%d\n",i>n?z:-1);
	}
	return 0;
}
