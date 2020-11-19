#include<stdio.h>
long long a[42]={0,1},s;
long long f[42]={0,1};
int n;
int main()
{
	for(int i=2;i<=40;i++)
	{
		for(int j=1;j<i;j++)
			a[i]+=f[j]*a[i-j];
		a[i]/=i-1;
		for(int j=1;j<=i;j++)
			if(i%j==0)
				f[i]+=j*a[j];
	}
	while(~scanf("%d",&n))
		printf("%I64d\n",a[n]);
}
