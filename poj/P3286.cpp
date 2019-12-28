#include<stdio.h>
long long a[12]={1,10,100,1000,10000,100000,1000000, 10000000,100000000,1000000000};
long long b[12]={0,1,11,192,2893,38894,488895,5888896,68888897,788888898};
long long c[12]={0,1,20,300,4000,50000,600000,7000000,80000000,900000000};
long long m,n;
long long zero(long long k)
{
	unsigned int kk,i,j,sum=0;
	if(k==0)
		return 0;
	for(i=9;i>=0;i--)
		if(a[i]<=k)
			break;
	kk=k-a[i];
	while(kk>=a[i])
	{
		kk-=a[i];
		sum++;
	}
	for(j=i-1;j>=0;j--)
		if(a[j]<=kk)
			break;
	sum=c[i]*sum+b[i]+(i-j-1)*kk;
	while(j!=-1)
		sum+=(a[j--]-1);
	return (sum+zero(kk));
}
int main()
{
	while(scanf("%I64d %I64d",&m,&n)&&m!=-1)
	{
		if(m==0)
			printf("%I64d\n",zero(n)+1);
		else
			printf("%I64d\n",zero(n)-zero(m-1));
	}
	return 0;
}
