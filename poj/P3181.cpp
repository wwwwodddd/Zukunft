#include<iostream>
using namespace std;
long long a[1100]={1},b[1100],inf;
int main()
{
	int n,k,i,j;
	for(inf=1,i=0;i<18;i++)
		inf*=10;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++)
		for(j=i;j<=n;j++)
		{
			b[j]=b[j]+b[j-i]+(a[j]+a[j-i])/inf;
			a[j]=(a[j]+a[j-i])%inf;
		}
	if(b[n])
		printf("%I64d",b[n]);
	printf("%I64d\n",a[n]);
	return 0;
}
