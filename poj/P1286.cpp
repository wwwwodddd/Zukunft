#include<stdio.h>
int n;
long long ans;
long long pw(int x,int y)
{
if(y==0)
	return 1;
return x*pw(x,y-1);
}
int gcd(int a,int b)
{
if(b==0)
	return a;
return gcd(b,a%b);
}
int main()
{
int i;
while(scanf("%d",&n)&&n!=-1)
	{
	ans=0;
	if(n==0)
		{
		printf("0\n");
		continue;
		}
	for(i=1;i<=n;i++)
		ans+=pw(3,gcd(n,i));
	if(n&1)
		ans+=n*pw(3,(n>>1)+1);
	else
		ans+=(n>>1)*pw(3,(n>>1))*4;
	printf("%I64d\n",ans/2/n);
	}
return 0;
}