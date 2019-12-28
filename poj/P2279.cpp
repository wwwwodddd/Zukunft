#include<stdio.h>
#include<string.h>
const int p[10]={2,3,5,7,11,13,17,19,23,29};
long long ans;
int c[20];
int b[6];
int n,i,j,sum;
void nu(int x)
{
	int i;
	for(i=0;i<10;i++)
		while(x%p[i]==0)
		{
		c[i]++;
		x/=p[i];
		}
	return;
}
void nd(int x)
{
	int i;
	for(i=0;i<10;i++)
		while(x%p[i]==0)
		{
		c[i]--;
		x/=p[i];
		}
	return;
}
int f(int h,int l)
{
	int i;
	for(i=0;h+i<n;i++)
		if(b[h+i]<=l)
			break;
return i;
}
int main()
{

	while(scanf("%d",&n)&&n)
	{
		memset(c,0,sizeof(c));
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			sum+=b[i];
		}
		for(i=1;i<=sum;i++)
			nu(i);
		for(i=0;i<n;i++)
			for(j=0;j<b[i];j++)
				nd(b[i]-j+f(i,j)-1);
		ans=1;
		for(i=0;i<10;i++)
			for(j=0;j<c[i];j++)
				ans*=p[i];
		printf("%I64d\n",ans);
	}
return 0;
}