#include<stdio.h>
long long a[30]={9,9,90,90,900,900,9000,9000,90000,90000,900000,900000,9000000,9000000,90000000,90000000,900000000,900000000,9000000000,9000000000,90000000000,90000000000,900000000000,900000000000};
int i;
long long n,m;
int main()
{
	while(scanf("%I64d",&n)&&n)
	{
		for(i=0;n>a[i];i++)
			n-=a[i];
		if(i&1)
		{
			for(i-=2;i>=0;i-=2)
				n+=a[i];
			m=n;
			printf("%I64d",n);
			while(m)
			{
				printf("%I64d",m%10);
				m/=10;
			}
		}
		else
		{
			for(i-=2;i>=0;i-=2)
				n+=a[i];
			m=n;
			printf("%I64d",n);
			m/=10;
			while(m)
			{
				printf("%I64d",m%10);
				m/=10;
			}
		}
		printf("\n");
	}
	return 0;
}