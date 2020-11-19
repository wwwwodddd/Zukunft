#include<stdio.h>
#include<math.h>
int n,i,j,k;
int main()
{
	while(scanf("%d",&n)+1)
	{
		for(i=1;i*i<=n;i++)
			for(j=i;i*i+j*j<=n;j++)
			{
				k=(int)sqrt((double)n-i*i-j*j);
				if(i*i+j*j+k*k==n&&k)
				{
					printf("%d %d %d\n",i,j,k);
					goto end;
				}
			}
		end:;
	}
	return 0;
}