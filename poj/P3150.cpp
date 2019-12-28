#include<stdio.h>
int n,m,d,k;
void mul(long long a[],long long b[])
{
	int i,j;
	long long c[501];
	for(i=0;i<n;++i)
		for(c[i]=j=0;j<n;++j)
			c[i]+=a[j]*b[(i-j+n)%n];
		for(i=0;i<n;i++)
			b[i]=c[i]%m;
}
long long init[501],tmp[501];
int main()
{
	int i,j;
	scanf("%d%d%d%d",&n,&m,&d,&k);
	for(i=0;i<n;++i)
		scanf("%I64d",&init[i]);
	for(tmp[0]=i=1;i<=d;++i)
		tmp[i]=tmp[n-i]=1;
	while(k)
	{
			if(k&1)
				mul(tmp,init);
			mul(tmp,tmp);
			k>>=1;
	}
	for(i=0;i<n;i++)
		printf("%I64d ",init[i]);
	printf("\n");
	return 0;
}